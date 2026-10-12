#include <bits/stdc++.h>

using namespace std;

vector<int> heavy;
vector<int> sz;
vector<int> parent;
vector<int> pos;
vector<int> head;
vector<int> a;
vector<int> st;
vector<int> depth;
int t=-1;
int BASE=1;
const int INF=1e9+100;

void dfs1(int node, int par, int d, vector<int> adj[]){
  parent[node]=par;
  depth[node]=d;
  int mx=0;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs1(adjN, node, d+1, adj);

    sz[node] += sz[adjN];
    if(sz[adjN] > mx){
      mx=sz[adjN]; heavy[node]=adjN;
    }
  }
}

void dfs2(int node, int h, vector<int> adj[]){
  head[node]=h;
  pos[node]=++t;
  if(heavy[node] != -1){
    dfs2(heavy[node], h, adj);
  }
  for(auto adjN : adj[node]){
    if(adjN == parent[node] || adjN == heavy[node]) continue;
    dfs2(adjN, adjN, adj);
  }
}

void update(int u, int val){
  a[u]=val;
  st[BASE+pos[u]]=val;
  for(int i=(BASE+pos[u])/2 ; i>0 ; i>>=1){
    st[i]=max(st[2*i],st[2*i+1]);
  }
}

int _get_max(int node, int l, int r, int ql, int qr){
  if(r<ql || qr<l) return -INF;
  if(ql<=l && r<=qr) return st[node];
  int mid=l+(r-l)/2;
  int left=_get_max(node*2, l, mid, ql, qr);
  int right=_get_max(node*2+1, mid+1, r, ql, qr);
  return max(left,right);
}

int get_max_2(int l, int r) {
    int res = 0;
    for (l += BASE, r += BASE + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, st[l++]);
        if (r & 1) res = max(res, st[--r]);
    }
    return res;
}

int get_max(int ql, int qr){
  return _get_max(1,0,BASE-1,ql,qr);
}

int get(int u, int v){
  int mx=0;
  while(head[u] != head[v]){
    if(depth[head[u]] < depth[head[v]]) swap(u,v);
    mx= max(mx, get_max_2(pos[head[u]], pos[u]));
    u=parent[head[u]];
  }
  if(depth[u] < depth[v]) swap(u,v);
  mx= max(mx, get_max(pos[v], pos[u]));
  return mx;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  a.resize(n);
  for(auto &x : a) cin >> x;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  parent.resize(n);
  heavy.resize(n,-1);
  sz.resize(n,1);
  depth.resize(n);
  dfs1(0,-1,0,adj);

  pos.resize(n);
  head.resize(n);
  dfs2(0,0,adj);

  while(BASE < n) BASE<<=1;
  st.resize(2*BASE);
  for(int i=0 ; i<n ; i++) st[BASE+pos[i]] = a[i];
  for(int i=BASE-1 ; i>0 ; i--) st[i] = max(st[2*i],st[2*i+1]);

  for(int rep=0 ; rep<m ; rep++){
    int type; cin >> type;
    if(type == 1){ // update 
      int u,val; cin >> u >> val; u--; 
      update(u,val);
    }else{ // get max
      int u,v; cin >> u >> v; u--; v--;
      cout<< get(u,v) <<" ";
    }
  }
  cout<<"\n";
}