#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n,m;
vector<int> tmp;
vector<vector<int>> ans;

struct Edge{
  int v;
  int cap;
  int rev;
  bool is_orig;
};

void bfs(int s, vector<int> &level, vector<vector<Edge>> &adj){
  level[s]=1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjN : adj[node]){
      if(level[adjN.v]==0 && adjN.cap>0){
        level[adjN.v] = level[node]+1;
        q.push(adjN.v);
      }
    }
  } 
}

int dfs(int node, int pushed, vector<int> &level, vector<int> &ptr, vector<vector<Edge>> &adj){
  if(node == n-1 || pushed == 0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp=dfs(adjN.v, min(pushed,adjN.cap), level, ptr, adj);

      if(tmp > 0){
        adjN.cap-=tmp;
        adj[adjN.v][adjN.rev].cap+=tmp;
        return tmp;
      }
    }
  }
  return 0;
}

bool dfs2(int node,vector<int> &path, vector<vector<Edge>> &adj){
  path.push_back(node);
  if(node == n-1) return true;
  for(Edge &adjN : adj[node]){
    if(adjN.is_orig && adjN.cap == 0){
      adjN.cap=1;
      bool ok=dfs2(adjN.v, path, adj);
      if(ok) return true;
    }
  }
  path.pop_back();
  return false;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  vector<vector<Edge>> adj(n);
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(Edge{v,1,adj[v].size(),true});
    adj[v].push_back(Edge{u,0,adj[u].size()-1,false});
  }

  int mx=0;
  while(true){
    vector<int> level(n);
    bfs(0,level,adj);
    if(level[n-1] == 0) break;

    vector<int> ptr(n);
    while(int flow = dfs(0,1e18, level, ptr, adj)) mx+=flow;
  }
  
  tmp.push_back(0);
  for(int i=0 ; i<mx ; i++){
    vector<int> path;
    dfs2(0, path, adj);
    ans.push_back(path);
  }
  
  cout<< mx <<"\n";
  for(auto &v : ans){
    cout<< v.size() <<"\n";
    for(auto &e : v){
      cout<< e+1 <<" ";
    }
    cout<<"\n";
  }
}