#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> up;
vector<int> a;
vector<int> depth;

const int LOG=30;

void dfs(int node, int par, int d, vector<int> adj[]){
  depth[node]=d;
  up[0][node]=par;
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

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;

  up.resize(LOG+1, vector<int>(n));
  depth.resize(n);
  a.resize(n);
  vector<int> adj[n];

  for(int i=1 ; i<n ; i++){
    int x; cin >> x; x--;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  dfs(0,0,0,adj);

  for(int i=1 ; i<=LOG ; i++){
    for(int j=0 ; j<n ; j++){
      up[i][j] = up[i-1][up[i-1][j]];
    }
  }

  for(int rep=0 ; rep<q ; rep++){
    int u,v; cin >> u >> v; u--; v--;
    if(depth[u] > depth[v]) swap(u,v); // u is always higher
    v = walk(v, depth[v]-depth[u]); // they are at the same depth
    if(u == v){ // already LCA
      cout<< u+1 <<"\n"; continue; 
    }

    for(int i=LOG ; i>=0 ; i--){
      if(up[i][u] != up[i][v]){
        u=up[i][u];
        v=up[i][v];
      }
    }

    cout<< up[0][u]+1 <<"\n";
  }
}