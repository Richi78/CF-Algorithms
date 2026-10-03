#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<pair<int,int>> adj[n];
  vector<int> degree(n);
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].emplace_back(v,i); degree[v]++;
    adj[v].emplace_back(u,i); degree[u]++;
  }

  for(int i=0 ; i<n ; i++) if(degree[i] & 1) {
    cout<<"IMPOSSIBLE\n"; return 0;
  }

  vector<bool> vis_edge(m);
  vector<int> circuit;
  stack<int> st;
  st.push(0);
  while(!st.empty()){
    int node = st.top();
    while(!adj[node].empty() && vis_edge[adj[node].back().second]){
      adj[node].pop_back();
    }
    if(!adj[node].empty()){
      auto [adjN,id] = adj[node].back();
      adj[node].pop_back();

      vis_edge[id] = true;
      st.push(adjN);
    }else{
      circuit.push_back(node);
      st.pop();
    }
  }

  if(circuit.size() != m+1){
    cout<<"IMPOSSIBLE\n"; return 0;
  }

  for(auto &x : circuit) cout<< x+1 <<" ";
  cout<<"\n";

}