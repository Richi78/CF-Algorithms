#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
vector<int> ans;
vector<int> a,b;

void dfs(int node, vector<int> adj[]){
  for(auto adjN : adj[node]){
    ans[adjN]=ans[node];
    if(mp[b[adjN]] == 0){
      ans[adjN]++;
    }
    mp[b[adjN]]++;
    dfs(adjN,adj);
    mp[b[adjN]]--;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n+1);  b.resize(n+1);
  for(int i=1 ; i<=n ; i++) cin >> a[i];
  for(int i=1 ; i<=n ; i++) cin >> b[i];
  vector<int> adj[n+1];
  for(int i=1 ; i<=n ; i++){
    adj[a[i]].push_back(i); 
  }

  ans.resize(n+1);
  dfs(0,adj);

  for(int i=1 ; i<=n ; i++)
    cout<< ans[i] <<" ";
  cout<<"\n";
}