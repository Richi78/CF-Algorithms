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
            dfs(adjN, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<bool> &vis, vector<int> &scc,
         int scc_number, vector<int> &fun, vector<int> &newfun){
    vis[node]=1;
    scc[node]=scc_number;
    newfun[scc_number-1]+=fun[node];
    for(auto adjN : adj[node]){
        if(!vis[adjN]){
            dfs2(adjN, adj, vis, scc, scc_number, fun, newfun);
        }
    }
}

int f(int from, int to, vector<int> adj[], vector<int> &fun, vector<int> &dp){
    if(from == to){
        return fun[to];
    }
    if(dp[from] != -1) return dp[from];
    int ans=0;
    for(auto adjN : adj[from]){
        int tmp=f(adjN, to , adj, fun, dp);
        uax(ans,tmp);
    }
    if(ans == 0){
        return dp[from]=0;
    }else{
        return dp[from]=ans+fun[from];
    }
}

void solve(){
    int n,m,s,e; cin >> n >> m >> s >> e;
    vector<int> fun(n);
    for(int i=0 ; i<n ; i++) cin >> fun[i];

    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    s--; e--;

    vector<bool> vis(n);
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
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
    vector<int> newfun(n);
    int scc_number=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc_number++;
            dfs2(node, adjT, vis, scc, scc_number, fun, newfun);
        }
    }

    vector<int> adjCond[scc_number];
    for(int i=0 ; i<n ; i++){
        for(auto adjN : adj[i]){
            if(scc[i] != scc[adjN]){
                adjCond[scc[i]-1].push_back(scc[adjN]-1);
            }
        }
    }

    // s -> e
    vector<int> dp(scc_number,-1);
    int ans=f(scc[s]-1, scc[e]-1, adjCond, newfun, dp);

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

