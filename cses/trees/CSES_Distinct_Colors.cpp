#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> heavy;
vector<int> sz;
vector<int> tin;
vector<int> tout;
vector<int> flat_tree;
vector<int> cnt;
vector<int> ans;
int distinct=0;
int t=-1;

void dfs1(int node, int par, vector<int> adj[]){
  tin[node]=++t;
  flat_tree[t]=node;
  int mx=0;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs1(adjN, node, adj);
    sz[node]+=sz[adjN];
    if(sz[adjN] > mx){
      mx=sz[adjN]; heavy[node]=adjN;
    }
  }
  tout[node]=t;
}

void add(int color){
  if(++cnt[color] == 1) distinct++;
}
void remove(int color){
  if(--cnt[color] == 0) distinct--;
}

void dfs2(int node, int par, vector<int> adj[], bool keep){
  for(auto adjN : adj[node]){
    if(adjN!=par && adjN!=heavy[node]){
      dfs2(adjN, node, adj, false);
    }
  }

  if(heavy[node] != -1){
    dfs2(heavy[node], node, adj, true);
  }

  for(auto adjN : adj[node]){
    if(adjN!=par && adjN!=heavy[node]){
      for(int i=tin[adjN] ; i<=tout[adjN] ; i++){
        add(a[flat_tree[i]]);
      }
    }
  }

  add(a[node]);
  ans[node] = distinct;
  if(!keep){
    for (int i=tin[node] ; i<=tout[node] ; i++) {
      remove(a[flat_tree[i]]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;

  vector<int> copy_a(a.begin() , a.end());
  sort(copy_a.begin() , copy_a.end());
  copy_a.erase( unique(copy_a.begin() , copy_a.end()) , copy_a.end());
  for(auto &x : a){
    x = lower_bound(copy_a.begin(), copy_a.end(), x) - copy_a.begin();
  }

  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  tin.resize(n);
  tout.resize(n);
  flat_tree.resize(n);
  sz.resize(n,1);
  heavy.resize(n,-1);
  dfs1(0,-1,adj); 

  cnt.resize(n);
  ans.resize(n);
  dfs2(0,-1,adj,true);

  for(auto &x : ans) cout<< x << " ";
  cout<<"\n";
}