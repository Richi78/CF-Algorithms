#include <bits/stdc++.h>

using namespace std;

vector<int> tin;
vector<int> tout;
vector<int> a;
vector<long long> st;
int t=-1;
int BASE=1;

void dfs(int node, int par, vector<int> adj[]){
  tin[node] = ++t;
  for(auto adjN : adj[node]) if(adjN != par){
    dfs(adjN, node, adj);
  }
  tout[node] = ++t;
}

void update(int u, int val){
  int delta = val - a[u];
  a[u]=val;
  for(int i=BASE+tin[u] ; i>0 ; i>>=1){
    st[i] += delta;
  }
  for(int i=BASE+tout[u] ; i>0 ; i>>=1){
    st[i] -= delta;
  }
}

long long _get(int node, int l, int r, int ql, int qr){
  if(r<ql || qr<l) return 0;
  if(ql<=l && r<=qr) return st[node];
  int mid=l+(r-l)/2;
  long long left = _get(node*2, l, mid, ql, qr);
  long long right = _get(node*2+1, mid+1, r, ql, qr);
  return left+right;
}

long long get(int ql, int qr){
  return _get(1,0,BASE-1,ql,qr);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  a.resize(n);
  for(auto &x: a) cin >> x;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  tin.resize(n);
  tout.resize(n);
  
  dfs(0,-1,adj);

  while(BASE < 2*n) BASE<<=1;
  st.resize(2*BASE);
  for(int i=0 ; i<n ; i++){
    st[BASE+tin[i]] = a[i];
    st[BASE+tout[i]] = -a[i];
  }
  for(int i=BASE-1 ; i>0 ; i--) st[i] = st[2*i] + st[2*i+1];

  for(int rep=0 ; rep<m ; rep++){
    int type; cin >> type;
    if(type == 1){
      int u,val; cin >> u >> val; u--;
      update(u,val);
    }else{
      int u; cin >> u; u--;
      cout<< get(tin[0], tin[u]) <<"\n";
    }
  }
}