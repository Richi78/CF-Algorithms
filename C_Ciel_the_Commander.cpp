#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

vector<bool> vis;
vector<char> ans;
vector<int> sz;

void dfs(int node, int parent, vector<int> adj[]){
    sz[node]=1;
    for(auto adjN : adj[node]){
        if(adjN==parent || vis[adjN]) continue;
        dfs(adjN, node, adj);
        sz[node]+=sz[adjN];
    }
}

int find_centroid(int node, int parent, vector<int> adj[], int n){
    for(auto adjN : adj[node]){
        if(adjN!=parent && !vis[adjN] && 2*sz[adjN] > n){
            return find_centroid(adjN,node, adj, n);
        }
    }
    return node;
}

void f(int node, char c, vector<int> adj[], int n){
    dfs(node, -1, adj);
    int centroid=find_centroid(node,-1,adj,sz[node]);
    vis[centroid]=true;
    ans[centroid]=c;

    for(auto adjN : adj[centroid]){
        if(!vis[adjN])
            f(adjN, c+1, adj, n);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // vdebug(sz)
    
    sz.resize(n);
    vis.resize(n);
    ans.resize(n);

    f(0, 'A', adj, n);

    for(auto x : ans) cout << x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}