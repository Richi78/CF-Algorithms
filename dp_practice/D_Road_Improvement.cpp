#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
vector<vector<int>> adj;
vector<long long> dp,up,ans;

void dfs(int node, int par){
  dp[node]=1;
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,node);
    dp[node]=dp[node] * ((dp[adjN]+1)%MOD) % MOD;
  }
}

void dfs2(int node, int par){
  vector<int> children;
  for(auto adjN : adj[node])if(adjN!=par)children.push_back(adjN);
  int sz=children.size();
  vector<long long> pref(sz+1,1) , suf(sz+1,1);
  for(int i=0 ; i<sz ; i++) pref[i+1]=pref[i]*((dp[children[i]]+1)%MOD)%MOD;
  for(int i=sz-1 ; i>=0 ; i--) suf[i]=suf[i+1]*((dp[children[i]]+1)%MOD)%MOD;
  for(int i=0 ; i<sz ; i++){
    int child=children[i];
    up[child]=pref[i]*suf[i+1]%MOD * ((up[node]+1)%MOD)%MOD;
    ans[child]=dp[child] * ((up[child]+1)%MOD) %MOD;
    dfs2(child,node);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  adj.resize(n);
  for(int i=1 ; i<n ; i++){
    int u; cin >> u; u--;
    adj[i].push_back(u);
    adj[u].push_back(i);
  }

  dp.resize(n);
  dfs(0,-1);
  ans.resize(n); up.resize(n);
  ans[0]=dp[0];
  dfs2(0,-1);
  for(auto &x : ans) cout<< x <<" ";
  cout<<"\n";
}