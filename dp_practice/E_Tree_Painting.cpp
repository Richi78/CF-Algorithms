#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<long long> dp;
long long sum=0, ans=0;

void dfs(int node, int par){
  dp[node]=1;
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,node);  
    dp[node]+=dp[adjN];
  }
  sum+=dp[node];
  ans=sum;
}

void dfs2(int node, int par){
  long long vpar=dp[par] , vnode=dp[node], vsum=sum;
  dp[par]-=vnode; dp[node]+=dp[par];
  sum+= dp[par]+dp[node]-vpar-vnode;
  ans=max(ans,sum);
  for(auto adjN : adj[node])if(adjN!=par)dfs2(adjN,node);
  sum=vsum;
  dp[par]=vpar; dp[node]=vnode;
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

  dp.resize(n);
  dfs(0,-1);
  for(auto adjN : adj[0]) dfs2(adjN,0);
  cout<< ans <<"\n";
}