#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<pair<int,int>> adj[n];
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    adj[u].emplace_back(v,w);
  }

  vector<long long> dist(n, INF);
  dist[0]=0;
  priority_queue<
    pair<long long, long long>, 
    vector<pair<long long, long long>>,
    greater<pair<long long, long long>>
  > pq;
  pq.push(make_pair(0,0));
  while(!pq.empty()){
    auto [d,node] = pq.top();
    pq.pop();
    if(d > dist[node]) continue;
    for(auto [adjN,w] : adj[node]){
      if(d+w < dist[adjN]){
        pq.push(make_pair(d+w,adjN));
        dist[adjN]=d+w;
      }
    }
  }

  for(auto &x : dist) cout<< x <<" ";
  cout<<"\n";
}