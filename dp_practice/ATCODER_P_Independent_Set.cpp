#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
vector<vector<int>> adj;
vector<array<int,2>> dp;

int dfs(int node, int par){
  if(adj[node].size()==1 && par!=-1){
    dp[node][0]=1; dp[node][1]=1;
    return 2;
  }
  long long w=1 , b=1;
  for(auto adjN :adj[node]) if(adjN != par){
    int tmp = dfs(adjN, node);
    w = w * tmp % MOD;
    b = b * dp[adjN][1] %MOD;
  }
  dp[node][0]=b; dp[node][1]=w;
  return (1LL * dp[node][0] + dp[node][1])%MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // dp[node][0/1] black/white
  dp.resize(n);
  cout<< dfs(0,-1) <<"\n";
}