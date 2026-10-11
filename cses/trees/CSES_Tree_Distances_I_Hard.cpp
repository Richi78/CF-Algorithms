#include <bits/stdc++.h>

using namespace std;


vector<int> parent;
vector<int> dist;
vector<int> dist_to_diameter;
vector<bool> in_diameter;
vector<int> idx;
int n;

int bfs(int s, vector<int> adj[]){
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

void dfs(int node, int par, vector<int> adj[]){
  for(auto adjN : adj[node]){
    if(adjN == par || in_diameter[adjN]) continue;
    dist_to_diameter[adjN] = dist_to_diameter[node]+1;
    parent[adjN]=parent[node];
    dfs(adjN, node, adj);
  }
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

  int node = bfs(0,adj);
  int other = bfs(node,adj);

  vector<int> diameter;
  for(int cur=other ; cur!=-1 ; cur=parent[cur]){
    diameter.push_back(cur);
  }
  reverse(diameter.begin() , diameter.end());
  in_diameter.resize(n);
  idx.resize(n); 
  for(int i=0 ; i<diameter.size() ; i++) in_diameter[diameter[i]]=true, idx[diameter[i]]=i;

  dist_to_diameter.resize(n);
  for(auto &x : diameter){
    parent[x]=x;
    dfs(x, -1, adj);
  }

  for(int i=0 ; i<n ; i++){
    cout<< (dist_to_diameter[i] + max(idx[parent[i]], (int)diameter.size()-1-idx[parent[i]]) ) <<" ";
  }
  cout<<"\n";
}