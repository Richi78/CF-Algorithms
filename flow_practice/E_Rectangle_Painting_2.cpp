#include <bits/stdc++.h>

using namespace std;

const long long iNF=1e18;

struct Edge{
  int v; long long cap; int rev;
};

vector<vector<Edge>> adj;
vector<int> level,ptr;

bool bfs(int s, int t){
  fill(level.begin() , level.end(), 0);
  level[s]=1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int node = q.front(); q.pop();
    for(auto &adjN : adj[node]){
      if(level[adjN.v]==0 && adjN.cap>0){
        q.push(adjN.v); level[adjN.v]=level[node]+1;
      }
    }
  }
  return level[t]>0;
}

int dfs(int node, long long pushed , int t){
  if(node==t || pushed==0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN=adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp = dfs(adjN.v, min(pushed,adjN.cap), t);
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
    fill(ptr.begin(), ptr.end(), 0);
    while(int pushed = dfs(s,1e9+100,t)) flow+=pushed;
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

  if(m==0){
    cout<<"0\n"; return 0;
  }
  vector<array<int,4>> rect;
  vector<int> r,c;
  for(int i=0 ; i<m ; i++){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    rect.push_back({x1,y1,x2,y2});
    r.push_back(x1); r.push_back(x2+1); c.push_back(y1); c.push_back(y2+1);
  }
  sort(r.begin(), r.end());
  r.resize(unique(r.begin(),r.end())-r.begin());
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(),c.end())-c.begin());
 
  vector<vector<bool>> isBlack(105,vector<bool>(105));
  for(auto &[x1,y1,x2,y2] : rect){
    x1=lower_bound(r.begin(), r.end(), x1)-r.begin();
    x2=lower_bound(r.begin(), r.end(), x2+1)-r.begin();

    y1=lower_bound(c.begin(), c.end(), y1)-c.begin();
    y2=lower_bound(c.begin(), c.end(), y2+1)-c.begin();

    for(int i=x1 ; i<x2 ; i++){
      for(int j=y1 ; j<y2 ; j++){
        isBlack[i][j]=true;
      }
    }
  }

  int nx = r.size()-1 , ny = c.size()-1;
  int S=nx+ny , T=nx+ny+1;
  adj.resize(nx+ny+2, vector<Edge>());
  level.resize(nx+ny+2); ptr.resize(nx+ny+2);
  for(int i=0 ; i<nx ; i++) add_edge(S,i,r[i+1]-r[i]);
  for(int i=0 ; i<ny; i++) add_edge(i+nx,T,c[i+1]-c[i]);
  for(int i=0 ; i<nx ; i++){
    for(int j=0 ; j<ny ; j++){
      if(isBlack[i][j]) add_edge(i,j+nx,1e18);
    }
  }

  cout<< dinic(S,T) <<"\n";
}