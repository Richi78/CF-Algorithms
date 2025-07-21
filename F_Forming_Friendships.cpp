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

void dfs(int s, vector<int> adj[], vector<int> &vis, int &nodes, int &edges){
    vis[s]=1;
    nodes++;
    for(auto adjN : adj[s]){
        edges++;
        if(vis[adjN] == 0){
            dfs(adjN, adj, vis, nodes, edges);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt=0;
    vector<int> vis(n+1);
    for(int i=1 ; i<=n ; i++){
        if(vis[i] == 0){
            int edges=0;
            int nodes=0;
            dfs(i , adj , vis , nodes , edges);
            int mx=nodes*(nodes-1)/2;
            cnt+=mx-edges/2;
        }
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

