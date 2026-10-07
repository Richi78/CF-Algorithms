#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v;
  int cap;
  int rev;
};

int n,m;

void bfs(int s, vector<int> &level, vector<vector<Edge>> &adj){
  queue<pair<int,int>> q;
  level[s]=1;
  q.push(make_pair(s,1));
  while(!q.empty()){
    auto [node, l] = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v]==0 && adjN.cap > 0){
        level[adjN.v]=l+1;
        q.push(make_pair(adjN.v,l+1));
      }
    }
  }
}

int dfs(int node, int pushed, vector<int> &level, vector<int> &ptr, vector<vector<Edge>> &adj){
  if(node == n-1 || pushed == 0){
    return pushed;
  }

  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v] == level[node]+1 && adjN.cap > 0){
      int tmp = dfs(adjN.v, min(pushed,adjN.cap), level, ptr, adj);

      if(tmp > 0){
        adjN.cap-=tmp;
        adj[adjN.v][adjN.rev].cap+=tmp;
        return tmp;
      }
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  vector<vector<Edge>> adj(n);
  vector<pair<int,int>> original_edges;
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(Edge{v,1,adj[v].size()});
    adj[v].push_back(Edge{u,1,adj[u].size()-1});
    original_edges.emplace_back(u,v);
  } 

  int source=0 , sink=n-1;
  int mx=0;
  while(true){
    vector<int> level(n);
    vector<int> ptr(n);
    bfs(source, level, adj);
    if(level[sink] == 0) break;

    while(int flow = dfs(source, 1e9, level, ptr, adj)){
      mx+=flow;
    }
  }
  cout<< mx <<"\n";

  vector<bool> vis(n);
  queue<int> q;
  q.push(source);
  vis[source]=true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjN :adj[node]){
      if(!vis[adjN.v] && adjN.cap > 0){
        vis[adjN.v]=true;
        q.push(adjN.v);
      }
    }
  }
  for(auto x : vis) cout<< x <<" "; cout<<"\n";
  for(auto [u,v] : original_edges){
    if(vis[u] != vis[v]){
      cout<< u+1 <<" "<< v+1 <<"\n";
    }
  }
}