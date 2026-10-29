#include <bits/stdc++.h>

using namespace std;

const int LOG=30;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int d, int par){
  depth[node] = d;
  up[0][node]=par;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs(adjN,d+1,node);
  }
}

int walk(int node, int steps){
  for(int i=0 ; i<=LOG ; i++){
    if( (steps>>i) & 1 ){
      node=up[i][node];
    }
  }
  return node;
}

int lca(int u, int v){
  if(depth[u] > depth[v]) swap(u,v);
  v=walk(v,depth[v]-depth[u]);
  if(u == v) return u;
  for(int i=LOG ; i>=0 ; i--){
    if(up[i][u] != up[i][v]){
      u=up[i][u];
      v=up[i][v];
    }
  }
  return up[0][u];
}

int dist(int u, int v){
  return depth[u]+depth[v]-2*depth[lca(u,v)];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,k; cin >> n >> k;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  up.resize(LOG+1, vector<int>(n));
  depth.resize(n);
  dfs(0,0,0);

  for(int i=1 ; i<=LOG ; i++){
    for(int j=0 ; j<n ; j++){
      up[i][j]=up[i-1][up[i-1][j]];
    }
  }

  int ans=0;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      if(i!=j && dist(i,j)==k) ans++;
    }
  }
  cout<< ans/2 <<"\n";
}