#include <bits/stdc++.h>

using namespace std;

long long mx=0;
vector<vector<pair<int,int>>> adj;
vector<long long> a;
vector<long long> dp;

void dfs(int node, int par){
  dp[node]=a[node];
  long long b1=0 , b2=0;

  for(auto &[adjN,w] : adj[node])if(adjN!=par){
    dfs(adjN,node);
    long long gain = max(0LL, dp[adjN]-w);
    if(gain > b1){
      b2=b1;
      b1=gain;
    }else if(gain > b2){
      b2=gain;
    }
  }
  mx=max(mx,a[node]+b1+b2);
  dp[node] = a[node] + b1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    long long u,v,w; cin >> u >> v >> w; u--; v--;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
  }

  dp.resize(n);

  dfs(0,-1);

  cout<< mx <<"\n";
}