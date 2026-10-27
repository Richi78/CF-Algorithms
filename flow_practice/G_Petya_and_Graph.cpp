#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+200;

struct Edge{
  int v;
  int cap;
  int rev;
};

vector<int> level,ptr;
vector<vector<Edge>> adj;
vector<array<int,3>> all_edges;

bool bfs(int s, int t){
  fill(level.begin() , level.end(), 0);
  level[s]=1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v] == 0 && adjN.cap > 0){
        q.push(adjN.v);
        level[adjN.v] = level[node]+1;
      }
    }
  }
  return level[t]>0;
}

int dfs(int node, int pushed, int t){
  if(node == t || pushed == 0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v] == level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v, min(pushed,adjN.cap), t);
      if(tmp>0){
        adjN.cap-=tmp;
        adj[adjN.v][adjN.rev].cap+=tmp;
        return tmp;
      }
    }
  }
  return 0;
}

long long dinic(int s, int t){
  long long flow=0;
  while(bfs(s,t)){
    fill(ptr.begin() , ptr.end() , 0);
    while(int pushed = dfs(s,1e9+100,t)) flow+=pushed;
  }
  return flow;
}

void add_edge(int u, int v, int cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
  all_edges.push_back({u,v,cap});
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<int> a(n);
  for(auto &x : a) cin >> x;

  int S=n+m , T=n+m+1;
  long long sum=0;
  adj.resize(n+m+2, vector<Edge>());
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    sum+=w;
    add_edge(S,i+n,w);
    add_edge(i+n,u,INF);
    add_edge(i+n,v,INF);
  }
  for(int i=0 ; i<n ; i++) add_edge(i,T,a[i]);

  level.resize(n+m+2);
  ptr.resize(n+m+2);
  long long flow = dinic(S,T);
  // min cut
  vector<bool> vis(n+m+2);
  vis[S]=true;
  queue<int> q;
  q.push(S);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(!vis[adjN.v] && adjN.cap>0){
        vis[adjN.v]=true;
        q.push(adjN.v);
      }
    }
  }

  for(auto adjN : adj[S]){
    cout<< adjN.cap <<" ";
  }
  cout<<"\n";

  long long x=0;
  for(auto [u,v,w] : all_edges){
    if(vis[u] && !vis[v]){
      cout<< u <<" , "<<v<<"\n";
    }
  }
  cout<< flow <<"\n";
  cout<< sum - flow <<"\n";
}