#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<array<long long,3>> edges;
  for(int i=0 ; i<m ; i++){
    long long u,v,w; cin >> u >> v >> w; u--; v--;
    edges.push_back({u,v,w});
  }

  vector<long long> dist(n);
  vector<int> parent(n,-1);
  for(int rep=0 ; rep<n-1 ; rep++){
    for(auto [u,v,w] : edges){
      if(dist[u]+w < dist[v]){
        dist[v]=dist[u]+w;
        parent[v]=u;
      }
    }
  }

  int last=-1;
  for(auto [u,v,w] : edges){
    if(dist[u]+w < dist[v]){
      dist[v]=dist[u]+w;
      parent[v]=u;
      last=v;
    }
  }

  if(last == -1){
    cout<< "-1\n"; return 0;
  }

  for(int i=0 ; i<n ; i++){
    last=parent[last];
  }

  vector<int> cycle;
  for(int cur=last ; ; cur=parent[cur]){
    cycle.push_back(cur);
    if(cur==cycle.front() && cycle.size()>1) break;
  }
  reverse(cycle.begin() , cycle.end());

  cout<< "YES\n";
  for(auto &x : cycle) cout<< x+1 <<" ";
  cout<<"\n";
}