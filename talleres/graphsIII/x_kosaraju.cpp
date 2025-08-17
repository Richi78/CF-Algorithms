#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void dfs(int node, vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &st){
    vis[node]=1;
    for(auto [adjN,adjW] : adj[node]){
        if(!vis[adjN]){
            dfs(adjN , adj , vis , st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<pair<int,int>> adj[], vector<bool> &vis,
        vector<int> &scc, int scc_number){
    vis[node]=1;
    scc[node]=scc_number;
    for(auto [adjN,adjW] : adj[node]){
        if(!vis[adjN]){
            dfs2(adjN , adj , vis , scc , scc_number);
        }
    }
}

int mush(int n){
    // int k = ( -1 + sqrt(1+8*n) ) / 2;
    int k=0;
    int l=0 , r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if( mid*(mid+1)/2 <= n){
            k=mid; l=mid+1;
        }else{
            r=mid-1;
        }
    }
    int term1 = (k+1) * n;
    int term2 = ( k * (k+1) * (k+2) ) / 6;
    return term1 - term2;
}

int f(int node, vector<pair<int,int>> adj[], vector<int> &add_scc, vector<int> &dp){
    if(dp[node] != -1) return dp[node];
    int ans=0;
    for(auto [adjN,adjW] : adj[node]){
        int tmp=adjW+f(adjN , adj , add_scc, dp);
        uax(ans, tmp);
    }
    return dp[node]=ans+add_scc[node];
}

void solve(){
    int n,m; cin >> n >> m;
    vector< pair<int,int> > adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v,w);
    }
    int root; cin >> root;
    root--;

    vector<bool> vis(n);
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i , adj , vis , st);
        }
    }

    vector<pair<int,int>> adjT[n];
    for(int i=0 ; i<n ; i++){
        vis[i]=0;
        for(auto [adjN,adjW] : adj[i]){
            adjT[adjN].push_back({i,adjW});
        }
    }

    vector<int> scc(n);
    int scc_number=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc_number++;
            dfs2(node, adjT, vis, scc, scc_number);
        }
    }

    vector<int> add_scc(scc_number);
    for(int i=0 ; i<n ; i++){
        int tmp=0;
        for(auto [adjN,adjW] : adj[i]){
            if(scc[adjN] == scc[i]){
                tmp+=mush(adjW);
                adjW=0;
            }
        }
        add_scc[scc[i]-1]+=tmp;
    }

    vector<pair<int,int>> adjCond[scc_number];
    for(int i=0 ; i<n ; i++){
        for(auto [adjN,adjW] : adj[i]){
            if(scc[i] != scc[adjN]){
                adjCond[scc[i]-1].emplace_back(scc[adjN]-1,adjW);
            }
        }
    }

    vector<int> dp(scc_number,-1);
    int ans=f(scc[root]-1, adjCond, add_scc, dp);

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}