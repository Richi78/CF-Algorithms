#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> up;
vector<int> depth;
vector<int> ans;

const int LOG=30;

void dfs(int node, int par, int d, vector<int> adj[]){
  up[0][node]=par;
  depth[node]=d;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs(adjN, node, d+1, adj);
  }
}

void dfs2(int node, int par, vector<int> adj[]){
  for(auto adjN : adj[node]){
    if(adjN == par) continue;
    dfs2(adjN, node, adj);
    ans[node]+=ans[adjN];
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

  int n,m; cin >> n >> m;

  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth.resize(n);
  up.resize(LOG+1, vector<int>(n));
  ans.resize(n);

  dfs(0,-1,0,adj);

  for(int i=1 ; i<=LOG ; i++) for(int j=0 ; j<n ; j++){
    if(up[i-1][j] == -1) up[i][j] = -1;
    else up[i][j] = up[i-1][up[i-1][j]];
  }

  for(int rep=0 ; rep<m ; rep++){
    int u,v; cin >> u >> v; u--; v--;
    int lca=get_lca(u,v);
    ans[u]++; ans[v]++; 
    ans[lca]--;
    if (up[0][lca] != -1) ans[up[0][lca]]--;
  }

  dfs2(0,-1,adj);

  for(auto &x : ans) cout<< x <<" ";
  cout<<"\n";
}