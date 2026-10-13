#include <bits/stdc++.h>

using namespace std;

vector<int> sz;
vector<bool> removed;
vector<int> cnt;
int n,k;
long long ans=0;

int dfs_size(int node, int par, vector<int> adj[]){
  sz[node]=1;
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs_size(adjN,node,adj);
    sz[node]+=sz[adjN];
  }
  return sz[node];
}

int get_centroid(int node, int par, int size, vector<int> adj[]){
  for(auto adjN : adj[node]){
    if(adjN != par && !removed[adjN] && sz[adjN] > size/2){
      return get_centroid(adjN, node, size, adj);
    }
  }
  return node;
}

void dfs_depth(int node, int par, int d, vector<int> &depth, vector<int> adj[]){
  if(d>k) return;
  depth.push_back(d);
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs_depth(adjN,node,d+1,depth,adj);
  }
}

void solve_centroid(int c, vector<int> adj[]){
  cnt[0]=1;

  int mx=0;
  vector<int> depth;
  for(auto adjN : adj[c]) if(!removed[adjN]){
    depth.clear();
    dfs_depth(adjN, c, 1, depth, adj);
    for(auto &d : depth) ans+=cnt[k-d];
    for(auto &d : depth) cnt[d]++, mx=max(mx,d);
  }

  for(int i=0 ; i<=mx ; i++) cnt[i]=0;
}

void decompose(int node, vector<int> adj[]){
  int total_nodes = dfs_size(node,-1,adj);
  int c = get_centroid(node, -1, total_nodes, adj);

  solve_centroid(c,adj);

  removed[c]=true;

  for(auto adjN : adj[c]) if(!removed[adjN]){
    decompose(adjN, adj); 
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  sz.resize(n);
  removed.resize(n);
  cnt.resize(n);
  decompose(0,adj);

  cout<< ans <<"\n";
}