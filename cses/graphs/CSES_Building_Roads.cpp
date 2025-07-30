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

void dfs(int node, int comp, vector<int> adj[], vector<int> &vis){
    vis[node]=comp;
    for(auto adjN : adj[node]){
        if(vis[adjN] == 0){
            dfs(adjN, comp, adj , vis);
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

    vector<int> vis(n+1);
    int cnt=0;
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            cnt++; 
            dfs(i, i, adj, vis);
        }
    }

    cout<< cnt-1 <<"\n";
    if(cnt-1){
        set<int> st(vis.begin()+1,vis.end());
        auto it=st.begin();
        while(next(it) != st.end()){
            cout<< *it <<" "<< *++it <<"\n";
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}