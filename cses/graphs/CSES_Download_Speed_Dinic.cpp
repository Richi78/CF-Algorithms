#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Edge{
  int v;
  int cap;
  int rev;
};

int n,m;
vector<vector<Edge>> adj;

void bfs(int s, vector<int> &level, vector<vector<Edge>> &adj){
  level[s]=1;
  queue<pair<int,int>> q;
  q.push(make_pair(s,1));
  while(!q.empty()){
    auto [node, l] = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v] == 0 && adjN.cap > 0){
        level[adjN.v] = l+1;
        q.push(make_pair(adjN.v , l+1));  
      }
    }
  }
}

int dfs(int node, int pushed, vector<int> &ptr, vector<int> &level, vector<vector<Edge>> &adj){
  if(node == n-1 || pushed == 0){
    return pushed;
  }
  for(int &cid = ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v] == level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v,min(pushed,adjN.cap),ptr,level,adj);
      
      if(tmp > 0){
        adjN.cap -= tmp;
        adj[adjN.v][adjN.rev].cap += tmp;
        return tmp;
      }
    }
  }
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  adj.resize(n);
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    adj[u].push_back(Edge{v,w,adj[v].size()});
    adj[v].push_back(Edge{u,0,adj[u].size()-1});
  }

  int mx=0;
  int source=0 , sink=n-1;

  while(true){
    vector<int> level(n);
    vector<int> ptr(n);
    bfs(source, level, adj);
    if(level[sink] == 0) break;

    while(int flow = dfs(source,1e18,ptr,level,adj)){
      mx+=flow;
    }
  }

  cout<< mx <<"\n";
}