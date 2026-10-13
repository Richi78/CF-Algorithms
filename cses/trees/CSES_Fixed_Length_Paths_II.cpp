#include <bits/stdc++.h>

using namespace std;

vector<int> st;
vector<int> touched;
int BASE=1;

void update(int node, int val){
  int idx=BASE+node;
  if(st[idx] == 0) touched.push_back(idx);
  st[idx]+=val;
  for(int i=idx/2 ; i>0 ; i>>=1){
    if(st[i] == 0) touched.push_back(i);
    st[i] += val;
  }
}

int get_sum_it(int ql, int qr){
  int res = 0;
  for (int l = BASE + ql, r = BASE + qr + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += st[l++];
    if (r & 1) res += st[--r];
  }
  return res;
}

const int N=2e5+1;
int n,k1,k2; 

vector<int> adj[N];
vector<int> sz(N);
vector<int> removed(N);
vector<int> depth;

long long ans=0;

void dfs_size(int node, int par){
  sz[node]=1;
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs_size(adjN,node);
    sz[node]+=sz[adjN];
  }
}

int find_centroid(int node, int par, int size){
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN] && sz[adjN]>size/2){
    return find_centroid(adjN,node,size);
  }
  return node;
}

void dfs_depth(int node, int par, int d, vector<int> &depth){
  if(d>k2) return;
  depth.push_back(d);
  for(auto adjN : adj[node]) if(adjN!=par && !removed[adjN]){
    dfs_depth(adjN,node,d+1,depth);
  }
}

void solve_centroid(int c){
  update(0,1);
  int mx=0;
  for(auto adjN : adj[c]) if(!removed[adjN]){
    depth.clear();
    dfs_depth(adjN,c,1,depth);

    for(auto &d : depth){
      int ql=max(0,k1-d);
      int qr=min(k2-d, mx);
      if(ql<=qr) ans+=get_sum_it(ql,qr);
    } 
    for(auto &d : depth){
      update(d,1); 
      mx=max(mx,d);
    } 
  }

  update(0,-1);
  for(int idx : touched) st[idx]=0;
  touched.clear();
}

void decompose(int node){
  dfs_size(node,-1);

  if (sz[node] <= k1) return;

  int c=find_centroid(node,-1,sz[node]);

  solve_centroid(c);

  removed[c]=true;

  for(auto adjN : adj[c]) if(!removed[adjN]){
    decompose(adjN);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k1 >> k2;
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  while(BASE <= k2) BASE<<=1;
  st.resize(2*BASE);
  touched.reserve(2*BASE);
  depth.reserve(N);
  
  decompose(0);

  cout<< ans <<"\n";
}