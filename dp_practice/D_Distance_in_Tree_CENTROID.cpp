#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> depth,sz;
vector<bool> removed;
vector<int> cnt(510), used(510);
int ans=0;
int n,k;

void dfs(int node, int d, int par){
  depth[node]=d;
  sz[node]=1;
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs(adjN,d+1,node);
    sz[node]+=sz[adjN];
  }
}

int get_centroid(int node, int len, int par){
  for(auto adjN : adj[node]){
    if(adjN!=par && !removed[adjN] && sz[adjN]>len/2){
      return get_centroid(adjN, len, node);
    }
  }
  return node;
}

void dfs2(int node, int d, int par, int &mx){
  if(d>k) return;
  depth[node]=d;
  used[d]++;
  mx=max(mx,d);
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs2(adjN,d+1,node,mx);
  }
}

void solve_centroid(int c){
  int mx2=0;
  cnt[0]=1;
  for(auto adjN : adj[c]) if(!removed[adjN]){
    int mx=0;
    dfs2(adjN,1,c,mx);
    mx2=max(mx2,mx);
    for(int i=0 ; i<=mx ; i++) if(used[i]) ans+=cnt[k-i]*used[i];
    for(int i=0 ; i<=mx ; i++) cnt[i]+=used[i];
    for(int i=0 ; i<=mx ; i++) used[i]=0;
  } 
  for(int i=0 ; i<=mx2 ; i++) cnt[i]=0;
}

void decomposite(int node){
  dfs(node,0,-1);
  int c = get_centroid(node, sz[node], -1);

  solve_centroid(c);

  removed[c]=true;

  for(auto adjN : adj[c]) if(!removed[adjN]){
    decomposite(adjN);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  removed.resize(n);
  sz.resize(n);
  depth.resize(n);

  decomposite(0);

  cout<< ans <<"\n";
}