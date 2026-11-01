#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<long long> a,dp;
long long val=0, ans=0;

void dfs(int node, int d, int par){
  dp[node]=a[node];
  val+=d*a[node];
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,d+1,node);
    dp[node]+=dp[adjN];
  }
}

void dfs2(int node, long long val, int par){
  long long vnode=dp[node];
  long long new_val=val-2*dp[node]+dp[par];
  ans=max(ans,new_val);
  dp[node]+=dp[par]-dp[node];
  for(auto adjN : adj[node])if(adjN!=par){
    dfs2(adjN,new_val,node);
  }
  dp[node]=vnode;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;

  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp.resize(n);
  dfs(0,0,-1);
  ans=val;
  for(auto adjN : adj[0]) dfs2(adjN,val,0);
  cout<< ans <<"\n";
}