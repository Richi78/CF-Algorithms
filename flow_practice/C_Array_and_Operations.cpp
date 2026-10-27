#include <bits/stdc++.h>

using namespace std;

const int N=1e9+10;
const int INF=1e9+100;
map<int,int> mp;
vector<int> primes;
vector<bool> sieve;

struct Edge{
  int v;
  int cap;
  int inv;
};

vector<vector<Edge>> adj;
vector<int> level,ptr;

bool bfs(int S, int T){
  fill(level.begin() , level.end(), 0);
  level[S]=1;
  queue<int> q;
  q.push(S);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(Edge adjN : adj[node]){
      if(level[adjN.v] == 0 && adjN.cap>0){
        q.push(adjN.v);
        level[adjN.v]=level[node]+1;
      }
    }
  }
  return level[T]>0;
}

int dfs(int node, int pushed, int T){
  if(node == T || pushed == 0) return pushed;
  for(int &cid=ptr[node] ; cid<adj[node].size() ; cid++){
    Edge &adjN = adj[node][cid];
    if(level[adjN.v] == level[node]+1 && adjN.cap>0){
      int tmp = dfs(adjN.v, min(pushed,adjN.cap), T);
      if(tmp > 0){
        adjN.cap -= tmp;
        adj[adjN.v][adjN.inv].cap += tmp;
        return tmp;
      }
    } 
  }
  return 0;
}

int dinic(int S, int T){
  int flow=0;
  while(bfs(S,T)){
    fill(ptr.begin() , ptr.end(), 0);
    while(int pushed = dfs(S,1e9,T)){
      flow+=pushed;
    }
  }
  return flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve.resize(32'000); // sqrt(1e9)
  for(int i=2 ; i<32'000 ; i++) if(!sieve[i]){
    primes.push_back(i);
    for(int j=i*i ; j<32'000 ; j+=i){
      sieve[j]=true;
    }
  }

  int n,m; cin >> n >> m;
  vector<int> a(n);
  vector<map<int,int>> factors(n);
  set<int> used_primes;
  for(int i=0 ; i<n ; i++){
    cin >> a[i];
    int tmp=a[i];
    for(auto p : primes){
      if(p*p > tmp) break; // probar eliminando
      while(tmp%p==0){
        factors[i][p]++; 
        tmp/=p;
        used_primes.insert(p);
      }
    }
    if(tmp>1){
      factors[i][tmp]++;
      used_primes.insert(tmp);
    } 
  } 

  vector<pair<int,int>> oddEven;
  for(int rep=0 ; rep<m ; rep++){
    int u,v; cin >> u >> v; u--; v--;
    if(u&1) swap(u,v);
    oddEven.emplace_back(u,v);
  }

  int S=n , T=n+1;
  int ans=0;
  level.resize(n+2);
  ptr.resize(n+2);
  for(auto p : used_primes){
    adj.assign(n+2, vector<Edge>());
    
    for(int i=0 ; i<n ; i++){
      if(factors[i][p] > 0){
        int cnt = factors[i][p];
        if(i%2 == 0){ // odd
          adj[S].push_back(Edge{i,cnt,adj[i].size()});
          adj[i].push_back(Edge{S,0,adj[S].size()-1});
        }else{
          adj[i].push_back(Edge{T,cnt,adj[T].size()});
          adj[T].push_back(Edge{i,0,adj[i].size()-1});
        }
      }
    }

    // valid edges
    for(auto [u,v] : oddEven){
      if(factors[u][p] && factors[v][p]){
        adj[u].push_back(Edge{v,INF,adj[v].size()});
        adj[v].push_back(Edge{u,0,adj[u].size()-1});
      }
    }
    ans += dinic(S,T);
  }  
  cout<< ans <<"\n";
}