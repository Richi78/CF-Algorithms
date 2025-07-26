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

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st){
    vis[node]=1;
    for(auto adjN : adj[node]){
        if(!vis[adjN]){
            dfs(adjN , adj , vis , st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<bool> &vis, int &cnt, 
        vector<int> &a, vector<int> &scc, int scc_number){
    vis[node]=1;
    scc[node]=scc_number;
    cnt+=a[node];
    for(auto adjN : adj[node]){
        if(!vis[adjN]){
            dfs2(adjN , adj , vis, cnt, a, scc, scc_number);
        }
    }
}

int f(int node, vector<int> adj[], vector<int> &a, vector<int> &dp){
    int ans=a[node];
    if(dp[node] != -1) return dp[node];
    for(auto adjN : adj[node]){
        uax(ans, a[node] + f(adjN , adj , a, dp));
    }
    return dp[node]=ans;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<bool> vis(n);
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i , adj , vis , st);
        }
    }

    vector<int> adjT[n];
    for(int i=0 ; i<n ; i++){
        vis[i]=0;
        for(auto adjN : adj[i]){
            adjT[adjN].push_back(i);
        }
    }

    vector<int> scc(n);
    vector<int> a2;
    int scc_number=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            int cnt=0;
            dfs2(node , adjT , vis, cnt, a, scc, scc_number);
            a2.push_back(cnt);
            scc_number++;
        }
    }

    vector<int> adjCondensed[n];

    for(int i=0 ; i<n ; i++){
        for(auto adjN : adj[i]){
            if(scc[i] != scc[adjN]){
                adjCondensed[scc[i]].push_back(scc[adjN]);
            }
        }
    }

    // vdebug(scc)
    // vdebug(a2)
    // for(auto x : adjCondensed){
        // vdebug(x)
    // }
    int ans=-1;
    vector<int> dp(scc_number,-1);
    for(int i=0 ; i<scc_number ; i++){
        uax(ans,f(i, adjCondensed, a2, dp));
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}