#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v; long long cap; int rev;
};

const int MAX_A=2e4+10;
vector<bool> isPrime(MAX_A,true);
vector<vector<Edge>> adj;
vector<int> level,ptr,a;

bool bfs(int s, int t){
  fill(level.begin() , level.end(), 0);
  level[s]=1; queue<int> q; q.push(s);
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
    Edge &adjN = adj[node][cid];
    if(level[adjN.v]==level[node]+1 && adjN.cap>0){
      int tmp = dfs(adjN.v , min(pushed,adjN.cap) , t);
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

  for(int i=2 ; i*i<MAX_A ; i++) if(isPrime[i]){
    for(int j=i*i ; j<MAX_A ; j+=i) isPrime[j]=false;
  }

  int n; cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;

  vector<vector<int>> ans;
  level.resize(n+2); ptr.resize(n+2);

  vector<int> e , o;
  for(int i=0 ; i<n ; i++){
    if(a[i]&1) o.push_back(i);
    else e.push_back(i);
  } 
  int ne=e.size() , no=o.size();
  if(ne != no){
    cout<< "Impossible\n"; return 0;
  }
  int S=ne+no , T=ne+no+1;
  adj.assign(ne+no+2,vector<Edge>());
  for(int i=0 ; i<ne ; i++) add_edge(S,i,2);
  for(int i=0 ; i<no ; i++) add_edge(i+ne,T,2);
  for(int i=0 ; i<ne ; i++) for(int j=0 ; j<no ; j++){
    if(isPrime[a[e[i]]+a[o[j]]]) add_edge(i,j+ne,1);
  }
  int K=dinic(S,T);
  if(K != n){
    cout<< "Impossible\n"; return 0;
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < ne; i++) {
    for (auto &adjN : adj[i]) {
      if (adjN.cap==0 && adjN.v>=ne && adjN.v<ne+no) {
        int u = e[i];
        int v = o[adjN.v - ne];
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
  }

  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vector<int> current_table;
    int curr = i;
    int prev = -1;
    while (!vis[curr]) {
      vis[curr] = true;
      current_table.push_back(curr); 

      int next_node = -1;
      for (int nxt : g[curr]) {
        if (nxt != prev && !vis[nxt]) {
          next_node = nxt;
          break;
        }
      }
      if (next_node == -1) break;
      prev = curr;
      curr = next_node;
    }
    ans.push_back(current_table);
  }

  cout<< ans.size() <<"\n";
  for(auto &v :ans){
    cout<< v.size() <<" ";
    for(auto &e : v) cout<< e+1 <<" ";
    cout<<"\n";
  }
}