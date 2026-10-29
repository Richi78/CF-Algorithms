#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;
int n,k;
int ans=0;

void dfs(int node, int par){
  dp[0][node]=1;
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,node);
    for(int i=0 ; i<k ; i++) ans+=dp[i][node]*dp[k-1-i][adjN];
    for(int i=0 ; i<k ; i++) dp[i+1][node]+=dp[i][adjN];
  }
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp.resize(k+1, vector<int>(n));

  dfs(0,-1);

  cout<< ans <<"\n";
}