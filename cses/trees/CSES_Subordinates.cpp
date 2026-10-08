#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int dfs(int node, vector<int> adj[]){
  int tmp=0;
  for(auto adjN : adj[node]){
    tmp += 1 + dfs(adjN,adj);
  }
  return ans[node]=tmp;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> adj[n];
  for(int i=1 ; i<n ; i++){
    int v; cin >> v; v--;
    adj[v].push_back(i);
  }

  ans.resize(n);
  dfs(0,adj);
  for(auto &x : ans) cout<< x <<" ";
  cout<<"\n";
}