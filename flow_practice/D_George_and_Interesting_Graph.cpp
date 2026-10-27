#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<<x<<"\n";

struct Edge{
  int v; long long cap; int rev;
};

vector<vector<Edge>> adj;
vector<pair<int,int>> edges;
vector<vector<bool>> vis;
vector<int> level,ptr;
int S,T;
int n,m;

bool bfs(int s, int t){
  fill(level.begin(), level.end(), 0);
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

int dfs(int node, long long pushed, int t){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN=adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v , min(pushed,adjN.cap), t);
      if(tmp == 0) continue;
      adjN.cap-=tmp;
      adj[adjN.v][adjN.rev].cap+=tmp;
      return tmp;
    }
  }
  return 0;
}

void add_edge(int u, int v, long long cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

long long dinic(int s, int t){
  long long flow=0;
  while(bfs(s,t)){
    fill(ptr.begin(), ptr.end(), 0);
    while(int pushed = dfs(s,1e18,t)) flow+=pushed;
  }
  return flow;
}

int f(int c){
  adj.assign(n+n+2, vector<Edge>());
  S=n+n; T=n+n+1;
  int cnt_edges=0;
  for(int i=0 ; i<n; i++) add_edge(S,i,1) , add_edge(i+n,T,1);
  for(auto [u,v] : edges){
    if(u==c || v==c) continue;
    add_edge(u,v+n,1);
    cnt_edges++;
  }

  int cnt=0;
  for(int j=0 ; j<n ; j++) if(!vis[c][j] && j!=c) cnt++;
  for(int i=0 ; i<n ; i++) if(!vis[i][c] && i!=c) cnt++;
  cnt+=!vis[c][c];
  int K=dinic(S,T);
  return cnt+n-1+cnt_edges-2*K;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  vis.resize(n,vector<bool>(n));
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    vis[u][v]=true;
    edges.emplace_back(u,v);
  }

  level.resize(n+n+2); ptr.resize(n+n+2);
  int mn=1e9;
  for(int i=0 ; i<n ; i++){
    mn=min(mn, f(i));
  }
  cout<< mn <<"\n";
}