#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> ans,a;

void dfs(int node, int par){
  ans[node]=a[node]==0?-1:1;
  for(auto adjN : adj[node])if(adjN!=par){
    dfs(adjN,node);
    ans[node]+=max(0,ans[adjN]);
  }
}

void dfs2(int node, int par){
  ans[node]+=max(0,ans[par]-max(0,ans[node]));
  for(auto adjN : adj[node])if(adjN!=par){
    dfs2(adjN,node);
  }
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

  ans.resize(n);
  dfs(0,-1);
  for(auto adjN : adj[0]){
    dfs2(adjN,0);
  }
  for(auto e : ans)cout<<e<<" "; cout<<"\n";
}