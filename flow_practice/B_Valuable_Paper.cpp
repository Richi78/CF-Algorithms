#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v; long long cap; int rev;
};

vector<int> level,ptr;
vector<array<long long,3>> edges;
int S,T;
int n,m;

bool bfs(int s, int t, vector<vector<Edge>> &adj){
  fill(level.begin() , level.end() , 0);
  level[s]=1;
  queue<int> q; q.push(s);
  while(!q.empty()){
    int node = q.front(); q.pop();
    for(auto adjN : adj[node]) if(level[adjN.v]==0 && adjN.cap>0){
      q.push(adjN.v); level[adjN.v]=level[node]+1;
    }
  }
  return level[t]>0;
}

int dfs(int node, long long pushed, int t, vector<vector<Edge>> &adj){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp = dfs(adjN.v, min(pushed, adjN.cap), t, adj);
      if(tmp == 0) continue;
      adjN.cap-=tmp;
      adj[adjN.v][adjN.rev].cap+=tmp;
      return tmp;
    }
  }
  return 0;
}

long long dinic(int s, int t, vector<vector<Edge>> &adj){
  long long flow=0;
  while(bfs(s,t,adj)){
    fill(ptr.begin() , ptr.end() , 0);
    while(int pushed = dfs(s,1e18,t, adj)) flow+=pushed;
  }
  return flow;
}

void add_edge(int u, int v, long long cap, vector<vector<Edge>> &adj){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

bool check(int mid, vector<vector<Edge>> &adj){
  adj.assign(2*n+2,vector<Edge>());
  for(int i=0 ; i<n ; i++) add_edge(S,i,1,adj) , add_edge(i+n,T,1,adj);
  for(auto [u,v,w] : edges){
    if(w<=mid) add_edge(u,v+n,1,adj);
  }
  return dinic(S,T,adj)==n;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    edges.push_back({u,v,w});
  }

  vector<vector<Edge>> adj;
  level.resize(2*n+2); ptr.resize(2*n+2);
  S=n+n , T=n+n+1;

  int l=0 , r=1e9+1;
  while(r-l>1){
    int mid=l+(r-l)/2;
    if(check(mid,adj)) r=mid;
    else l=mid;
  }
  cout<< (r==1e9+1 ? -1 : r) <<"\n";
}