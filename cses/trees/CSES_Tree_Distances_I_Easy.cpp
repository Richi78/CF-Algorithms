#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
int n;

int bfs(int s, vector<int> &dist, vector<int> adj[]){
  parent.assign(n,-1);
  dist.assign(n,0);
  queue<pair<int,int>> q;
  q.push(make_pair(s,0));
  while(!q.empty()){
    auto [node,dis] = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(adjN == parent[node]) continue;
      if(dist[adjN] == 0){
        dist[adjN] = dis+1;
        parent[adjN]=node;
        q.push(make_pair(adjN,dis+1));
      }
    }
  }
  int mx=0 , node;
  for(int i=0 ; i<n ; i++) if(dist[i] > mx) mx=dist[i], node=i;
  return node;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  if(n == 1){
    cout<< "0\n"; return 0;
  }

  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist(n);
  int node = bfs(0, dist, adj);
  vector<int> dist1(n);
  int other = bfs(node, dist1, adj);
  vector<int> dist2(n);
  bfs(other, dist2, adj);

  for(int i=0 ; i<n ; i++){
    cout<< max(dist1[i], dist2[i]) <<" ";
  }
  cout<<"\n";
}