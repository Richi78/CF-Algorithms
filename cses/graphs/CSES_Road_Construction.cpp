#include <bits/stdc++.h>

using namespace std;

struct DSU{
  vector<int> parent,size;
  int groups , mx;
  DSU(int n){
    parent.resize(n);
    size.resize(n,1);
    for(int i=0 ; i<n ; i++) parent[i] = i;
    groups=n; mx=1;
  }
  int find(int node){
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
  }
  void unite(int a, int b){
    int A=find(a) , B=find(b);
    if(A == B) return;
    groups--;
    if(size[A] > size[B]){
      parent[B]=A;
      size[A]+=size[B];
      mx=max(mx, size[A]);
    }else{
      parent[A]=B;
      size[B]+=size[A];
      mx=max(mx,size[B]);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  DSU dsu(n);
  for(int rep=0 ; rep<m ; rep++){
    int u,v; cin >> u >> v; u--; v--;
    dsu.unite(u,v);
    cout<< dsu.groups <<" "<< dsu.mx <<"\n";
  }
}