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

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &vis_path){
    vis[node]=true;
    vis_path[node]=true;
    bool ans=false;
    for(auto adjN : adj[node]){
        if(!vis[adjN]){
            ans|=dfs(adjN, adj, vis , vis_path);
            if(ans) return true;
        }else if(vis_path[adjN]){
            return true;
        }
    }
    vis_path[node]=false;
    return false;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    bool ok=false;
    vector<bool> vis(n) , vis_path(n);
    for(int i=0 ; i<n && !ok ; i++){
        if(!vis[i]){
            ok|=dfs(i, adj, vis, vis_path);
        }
    }

    cout<< ok <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}