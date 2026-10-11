#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int dfs(int node, int parent, vector<int> adj[]){
  if(adj[node].size() == 0) return 0;
  int sum=0;
  for(int adjN : adj[node]){
    if(adjN != parent){
      dfs(adjN, node, adj);
      sum += max(dp[0][adjN], dp[1][adjN]);
    } 
  }
  for(auto adjN : adj[node]){
    if(adjN == parent) continue;
    dp[1][node] = max(dp[1][node], sum - max(dp[0][adjN], dp[1][adjN]) + (dp[0][adjN]+1) );
  }
  dp[0][node] = max(dp[0][node], sum);
  return max(dp[0][node], dp[1][node]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dp.resize(2, vector<int>(n));

  cout<< dfs(0,-1,adj) <<"\n";
}