#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> dp;
vector<int> sz;

void dfs1(int node, int par, int depth, vector<int> adj[]){
  dp[0]+=depth;
  for(auto adjN : adj[node]){
    if(adjN != par){
      dfs1(adjN, node, depth+1, adj);
      sz[node]+=sz[adjN];
    }
  } 
}

void dfs2(int node, int par, vector<int> adj[]){
  dp[node] = dp[par] - sz[node] + n - sz[node];
  for(auto adjN : adj[node]) if(adjN != par){
    dfs2(adjN,node,adj);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp.resize(n);
  sz.resize(n,1);

  dfs1(0,-1,0,adj);

  for(auto adjN : adj[0]){
    dfs2(adjN,0,adj);
  }
  
  for(auto &x : dp) cout<< x <<" ";
  cout<<"\n";
}