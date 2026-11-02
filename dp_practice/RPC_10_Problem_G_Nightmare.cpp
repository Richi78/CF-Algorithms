#include <bits/stdc++.h>

using namespace std;

struct DSU{
  vector<int> parent,sz;
  DSU(int n=0){
    init(n);
  }
  void init(int n){
    parent.resize(n); sz.resize(n,1);
    for(int i=0 ; i<n ; i++) parent[i]=i;
  }
  int find(int node){
    if(node == parent[node]) return node;
    return parent[node]=find(parent[node]);
  }
  void unite(int a, int b){
    int A=find(a) , B=find(b);
    if(A==B) return;
    if(sz[A]>sz[B]){
      sz[A]+=sz[B];
      parent[B]=A;
    }else{
      sz[B]+=sz[A];
      parent[A]=B;
    }
  }
};

vector<array<int,3>> r,b;
DSU dsuR , dsuB;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w;
    if(w == 0) r.push_back({u,v,w});
    else b.push_back({u,v,w});
  }

  dsuB=DSU(n);
  for(auto &[u,v,w] : b){
    dsuB.unite(u,v);
  }
  dsuR=DSU(n);
  for(auto &[u,v,w] : r){
    if(dsuB.find(u) == dsuB.find(v)){
      cout<<"NO\n"; return 0;
    }
    dsuR.unite(u,v);
  }
  for(auto &[u,v,w] : b){
    if(dsuR.find(u) == dsuR.find(v)){
      cout<<"NO\n"; return 0;
    }
  }
  cout<<"YES\n";
}