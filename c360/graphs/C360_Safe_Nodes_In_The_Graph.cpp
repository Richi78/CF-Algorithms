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

bool dfs(int node, vector<int> adj[], vector<bool> &vis,
     vector<bool> &vis_path, vector<int> &ans){
    vis[node]=true;
    vis_path[node]=true;
    bool ok=true;
    for(auto adjN : adj[node]){
        if(!vis[adjN]){
            ok&=dfs(adjN, adj, vis, vis_path, ans);
            if(!ok) return false;
        }else if(vis_path[adjN]){
            // cycle
            return false;
        }
    }
    vis_path[node]=false;
    ans.push_back(node);
    return ok;
}

void solve(){
    int n,e; cin >> n >> e;

    vector<int> adj[n];
    for(int i=0 ; i<e ; i++){
        // adj[edges[i][0]].push_back(edges[i][1]);
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(n);
    vector<bool> vis_path(n);
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i, adj, vis, vis_path, ans);
        }
    }
    sort(ans.begin() , ans.end());
    // return ans;
    for(auto x : ans){
        cout<< x <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

