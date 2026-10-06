#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;

  int nodes = 1 << n;
  int m = (1<<n-1) - 1;
  vector<int> adj[nodes];
  for(int i=0 ; i<nodes ; i++){
    int edge_0 = ((i&m) << 1) | 0;
    int edge_1 = ((i&m) << 1) | 1;
    adj[i].push_back(edge_0);
    adj[i].push_back(edge_1);
  }

  // SE CANCELA, VA DAR TLE O( 2^(2^n) )
  // dp[node][mask] = mask is visited, node is current
  vector<vector<int>> dp(n,vector<int>(nodes));
  dp[0][1 << 0]=1;
  for(int mask=1 ; mask<nodes ; mask++){
    for(int node=0 ; node<n ; node++){
      // if mask includes node continue
      if(!dp[node][mask]) continue;
      if(mask & (1<<node)) continue;
      for(int adjN : adj[node]){
        if(mask & (1 << adjN)) continue;
        dp[adjN][mask | 1<<adjN]=1;
      }
    }
  }
}