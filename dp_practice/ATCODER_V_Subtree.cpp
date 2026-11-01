#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<long long> dp,depth,up;
int n,MOD; 
vector<long long> ans;
void dfs(int node, int par){
  dp[node]=1;
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,node);
    dp[node]=dp[node]*((dp[adjN]+1)%MOD)%MOD;
  }
}

void dfs2(int node, int par){
  vector<int> children;
  for(auto adjN : adj[node])if(adjN!=par)children.push_back(adjN);
  int sz=children.size();
  vector<long long> pref(sz+1,1) , suf(sz+1,1);
  for(int i=0 ; i<sz ; i++){
    pref[i+1]=pref[i]*((dp[children[i]]+1)%MOD)%MOD;
  }
  for(int i=sz-1 ; i>=0 ; i--){
    suf[i]=suf[i+1]*((dp[children[i]]+1)%MOD)%MOD;
  }
  for(int i=0 ; i<sz ; i++){
    up[children[i]]=pref[i]*suf[i+1]%MOD * ((up[node]+1)%MOD) %MOD;
    ans[children[i]] = dp[children[i]] * ((up[children[i]]+1)%MOD) %MOD;
    dfs2(children[i],node);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> MOD;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp.resize(n);
  dfs(0,-1);
  up.resize(n);
  ans.resize(n);
  ans[0]=dp[0];
  dfs2(0,-1);
  
  for(auto &x : ans) cout<< x <<"\n";
}