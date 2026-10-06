#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;

void add_self(int &a, int b){
  a+=b;
  if(a>=MOD) a-=MOD;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<int> adj[n];
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
  }

  vector<vector<int>> dp(n,vector<int>((1<<n),0));
  dp[0][1<<0]=1;
  int total_mask = 1<<n;
  for(int mask=1 ; mask<total_mask; mask++){
    if(!(mask&1)) continue;
    if ((mask & (1 << (n - 1))) && mask != total_mask-1) continue;
    for(int node=0 ; node<n ; node++){
      if(!dp[node][mask]) continue;
      for(auto adjN : adj[node]){
        if(mask & (1<<adjN)) continue;
        add_self(dp[adjN][mask | 1<<adjN] , dp[node][mask]);
      }
    }
  }

  cout<< dp[n-1][(1<<n)-1] <<"\n";
}