#include <bits/stdc++.h>

using namespace std;

vector<int> depth;
vector<vector<int>> up;

const int LOG=30;

void dfs(int node, int par, int d, vector<int> adj[]){
  depth[node] = d;
  up[0][node] = par;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs(adjN, node, d+1, adj);
  }
}

int walk(int node, int step){
  for(int i=0 ; i<=LOG ; i++) if((step>>i) & 1){
    node = up[i][node];
  }
  return node;
}

int get_lca(int u, int v){
  if(depth[u] > depth[v]) swap(u,v);
  v = walk(v, depth[v]-depth[u]);
  if(u == v) return u;
  for(int i=LOG ; i>=0 ; i--){
    if(up[i][u] != up[i][v]){
      u=up[i][u];
      v=up[i][v];
    }
  }
  return up[0][u];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth.resize(n);
  up.resize(LOG+1, vector<int>(n));

  dfs(0,0,0,adj);

  for(int i=1 ; i<=LOG ; i++) for(int j=0 ; j<n ; j++){
    up[i][j] = up[i-1][up[i-1][j]];
  }

  for(int rep=0 ; rep<q ; rep++){
    int u,v; cin >> u >> v; u--; v--;
    int lca = get_lca(u,v);
    cout<< depth[u] + depth[v] - 2*depth[lca] <<"\n";
  }
}