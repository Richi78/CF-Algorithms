#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v;
  int cap;
  int rev;
};

int n,m,k;
int total_nodes;
void bfs(int s, vector<int> &level, vector<vector<Edge>> &adj){
  level[s]=1;
  queue<pair<int,int>> q;
  q.push(make_pair(s,1));
  while(!q.empty()){
    auto [node,l] = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v] == 0 && adjN.cap > 0){
        level[adjN.v]=l+1;
        q.push(make_pair(adjN.v,l+1));
      }
    }
  }
}

int dfs(int node, int pushed, vector<int> &level, vector<int> &ptr, vector<vector<Edge>> &adj){
  if(node == total_nodes-1 || pushed == 0){
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

  cin >> n >> m >> k;
  total_nodes = n+m+2;
  vector<vector<Edge>> adj(total_nodes);
  for(int i=0 ; i<k ; i++){
    int u,v; cin >> u >> v; v+=n;
    adj[u].push_back(Edge{v,1,adj[v].size()});
    adj[v].push_back(Edge{u,0,adj[u].size()-1});
  }
  for(int i=1 ; i<=n ; i++){
    adj[0].push_back(Edge{i,1,adj[i].size()});
    adj[i].push_back(Edge{0,0,adj[0].size()-1});
  }
  for(int i=n+1 ; i<=n+m ; i++){
    adj[total_nodes-1].push_back(Edge{i , 0 , adj[i].size()});
    adj[i].push_back(Edge{total_nodes-1 , 1 , adj[total_nodes-1].size()-1});
  }

  int source=0 , sink=total_nodes-1;
  int mx=0;
  while(true){
    vector<int> level(total_nodes);
    vector<int> ptr(total_nodes);
    bfs(source, level, adj);
    if(level[sink] == 0) break;
    while(int flow = dfs(source, 1e9, level, ptr, adj)){
      mx+=flow;
    }
  }
  cout<< mx <<"\n";
  for(int node=1 ; node<=n ; node++){
    for(auto &adjN: adj[node]){
      if(adjN.v > n && adjN.cap == 0){
        int girl = adjN.v-n;
        cout<< node <<" "<< girl <<"\n";
        break;
      }
    }
  }
}