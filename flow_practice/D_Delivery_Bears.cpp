#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v; long long cap; int rev;
};

vector<int> level,ptr;
vector<vector<Edge>> adj;
vector<array<int,3>> edges;
int n,m,x;

bool bfs(int s, int t){
  fill(level.begin(), level.end() , 0);
  queue<int> q;
  level[s]=1;
  q.push(s);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v]==0 && adjN.cap>0){
        q.push(adjN.v);
        level[adjN.v]=level[node]+1;
      }
    }
  }
  return level[t]>0;
}

int dfs(int node, long long pushed, int t){
  if(node == t || pushed == 0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
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

long long dinic(int s, int t){
  long long flow=0;
  while(bfs(s,t)){
    fill(ptr.begin(), ptr.end(),0);
    while(int pushed = dfs(s,1e9+100,t)) flow+=pushed;
  }
  return flow;
}

void add_edge(int u, int v, int cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

bool check(double W){
  adj.assign(n,vector<Edge>());
  int S=0 , T=n-1;
  for(auto [u,v,c] : edges){
    long long bear=c/W; 
    add_edge(u,v,min(1LL*x,bear));
  } 
  return dinic(S,T)>=x;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout<< setprecision(10) <<fixed;

  cin >> n >> m >> x;
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    edges.push_back({u,v,w});
  }

  level.resize(n); ptr.resize(n);
  double l=0 , r=1'000'001;
  for(int rep=0 ; rep<80 ; rep++){
    double mid=l+(r-l)/2.0;
    if(check(mid)) l=mid;
    else r=mid;
  }
  cout<< (double)x*l <<"\n"; 
}