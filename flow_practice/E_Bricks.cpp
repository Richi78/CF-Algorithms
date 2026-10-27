#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": "; for(auto e : x) cout<< e <<" "; cout<<"\n";

struct Edge{
  int v; long long cap; int rev;
};

vector<vector<Edge>> adj;
vector<int> level,ptr;
int nx=0 , ny=0;

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

int dfs(int node, long long pushed, int t){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN=adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp = dfs(adjN.v, min(pushed,adjN.cap),t);
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
    fill(ptr.begin() , ptr.end(), 0);
    while(int pushed = dfs(s,1e18,t)) flow+=pushed;
  }
  return flow;
}

void add_edge(int u, int v, long long cap){
  adj[u].push_back(Edge{v,cap,adj[v].size()});
  adj[v].push_back(Edge{u,0,adj[u].size()-1});
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<string> a(n);
  vector<vector<int>> px(n,vector<int>(m));
  vector<vector<int>> py(n,vector<int>(m));
  int black=0;
  for(auto &x : a){
    cin >> x;
    for(int i=0 ; i<m ; i++) black+=x[i]=='#';
  }
  
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m-1 ; j++){
      if(a[i][j]=='#' && a[i][j+1]=='#') px[i][j]=++nx;
    }
  }

  for(int i=0 ; i<n-1 ; i++){
    for(int j=0 ; j<m ; j++){
      if(a[i][j]=='#' && a[i+1][j]=='#') py[i][j]=++ny;
    }
  }

  for(auto row : px){
    for(auto col : row) cout<< col << " ";
    cout<<"\n";
  }
  cout<<"------\n";
  for(auto row : py){
    for(auto col : row) cout<< col << " ";
    cout<<"\n";
  }

  adj.resize(nx+ny+2, vector<Edge>());
  level.resize(nx+ny+2); ptr.resize(nx+ny+2);
  int S=0 , T=nx+ny+1;
  for(int i=1 ; i<=nx ; i++) add_edge(S,i,1);
  for(int i=1 ; i<=ny ; i++) add_edge(i+nx,T,1);
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m ; j++){
      if(a[i][j]=='.') continue;
      vector<int> x_adj , y_adj;
      if(j>0 && px[i][j-1]) x_adj.push_back(px[i][j-1]);
      if(j<m-1 && px[i][j]) x_adj.push_back(px[i][j]);
      if(i>0 && py[i-1][j]) y_adj.push_back(py[i-1][j]);
      if(i<n-1 && py[i][j]) y_adj.push_back(py[i][j]);
      cout<<"J: "<<j<<"\n";
      vdebug(x_adj)
      vdebug(y_adj)
      cout<<"......\n";
      for(int x : x_adj){
        for(int y : y_adj){
          add_edge(x,y+nx,1);
        }
      }
    }
  }

  cout<< (black - ((nx+ny) - dinic(S,T))) <<"\n";
}