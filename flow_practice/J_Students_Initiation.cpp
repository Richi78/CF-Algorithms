#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v; int cap; int rev;
};

vector<vector<Edge>> adj;
vector<int> level,ptr;
vector<pair<int,int>> edges;
int n,m,S,T;

bool bfs(int s, int t, vector<vector<Edge>> &g){
  fill(level.begin(), level.end(),0);
  level[s]=1;
  queue<int> q; q.push(s);
  while(!q.empty()){
    int node = q.front(); q.pop();
    for(auto adjN : g[node]) if(level[adjN.v]==0 && adjN.cap>0){
      q.push(adjN.v); level[adjN.v]=level[node]+1;
    }
  }
  return level[t]>0;
}

int dfs(int node, int pushed, int t, vector<vector<Edge>> &g){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<g[node].size() ; cid++){
    Edge &adjN=g[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v, min(pushed,adjN.cap), t, g);
      if(tmp == 0) continue;
      adjN.cap-=tmp;
      g[adjN.v][adjN.rev].cap+=tmp;
      return tmp;
    }
  }
  return 0;
}

int dinic(int s, int t, vector<vector<Edge>> &g){
  int flow=0;
  while(bfs(s,t,g)){
    fill(ptr.begin(), ptr.end(), 0);
    while(int pushed = dfs(s,1e9+100,t,g)) flow+=pushed;
  }
  return flow;
}

void add_edge(int u, int v, int cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

bool check(int mid, vector<vector<Edge>> g){
  for(int i=0 ; i<n ; i++){
    g[i+m].push_back(Edge{T,mid,g[T].size()});
    g[T].push_back(Edge{i+m,0,g[i+m].size()-1});
  }
  return dinic(S,T,g) == m;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  int total_nodes = n+m+2;
  adj.assign(total_nodes,vector<Edge>());
  level.resize(total_nodes); ptr.resize(total_nodes);
  S=n+m; T=n+m+1;
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    edges.emplace_back(u,v);
    add_edge(S,i,1);
    add_edge(i,u+m,1);
    add_edge(i,v+m,1);
  }

  if(m == 0){
    cout<<"0\n"; return 0;
  }

  int l=0 , r=5'500;
  while(r-l>1){
    int mid=l + (r-l)/2;
    if(check(mid, adj)) r=mid;
    else l=mid;
  }

  for(int i=0 ; i<n ; i++) add_edge(i+m,T,r);
  int flow = dinic(S,T,adj);

  for(int i=0 ; i<m ; i++){
    for(auto adjN : adj[i]){
      if(adjN.v == S) continue;
      if(adjN.cap == 0){
        if(edges[i].second == adjN.v-m) 
          swap(edges[i].first , edges[i].second);
      }
    }
  }

  cout<< r <<"\n";
  for(auto [u,v] : edges) cout<< u+1 <<" "<< v+1 <<"\n";
}