#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

struct Edge{
  int v; int cap; int rev;
};

int n,m;
vector<vector<Edge>> adj;
vector<int> level,ptr;
vector<int> a,b;

void add_edge(int u, int v, int cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

bool bfs(int s, int t){
  fill(level.begin() , level.end(), 0);
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

int dfs(int node, int pushed, int t){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN=adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v, min(pushed,adjN.cap), t);
      if(tmp == 0) continue;
      adjN.cap-=tmp;
      adj[adjN.v][adjN.rev].cap+=tmp;
      return tmp;
    }
  }
  return 0;
}

int dinic(int s, int t){
  int flow=0;
  while(bfs(s,t)){
    fill(ptr.begin() , ptr.end(), 0);
    while(int pushed = dfs(s,INF,t)) flow+=pushed;
  }
  return flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  a.resize(n); b.resize(n);
  int A=0 , B=0;
  for(auto &x : a) cin >> x , A+=x; 
  for(auto &x : b) cin >> x , B+=x; 

  if(A != B){
    cout<<"NO\n"; return 0;
  }

  adj.assign(2*n+2,vector<Edge>());
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    add_edge(2*u,2*v+1,INF);
    add_edge(2*v,2*u+1,INF);
  }
  int S=2*n , T=2*n+1;
  level.resize(2*n+2); ptr.resize(2*n+2);
  for(int i=0 ; i<n ; i++){
    add_edge(2*i,2*i+1,INF); 
    add_edge(S,2*i,a[i]);
    add_edge(2*i+1,T,b[i]);
  }

  int flow = dinic(S,T);
  if(flow != A){
    cout<<"NO\n"; return 0;
  }
  
  vector<vector<int>> mat(n, vector<int>(n));
  for(int u=0 ; u<n ; u++){
    for(auto &adjN : adj[2*u]){
      if(adjN.v == S) continue;
      int v=adjN.v/2;
      mat[u][v] = adj[adjN.v][adjN.rev].cap;
    }
  }
  cout<<"YES\n";
  for(auto &row : mat){
    for(auto &col : row) cout<< col <<" ";
    cout<<"\n";
  }
}