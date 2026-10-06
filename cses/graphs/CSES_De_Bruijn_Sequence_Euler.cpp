#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  if(n == 1){ cout<<"01\n"; return 0;}

  int nodes = 1 << n-1;
  int mask = nodes - 1;

  vector<pair<int,int>> adj[nodes];
  for(int i=0 ; i<nodes ; i++){
    int edge_0 = (i<<1 | 0) & mask; 
    int edge_1 = (i<<1 | 1) & mask;
    adj[i].emplace_back(edge_0,0);
    adj[i].emplace_back(edge_1,1);
  }

  vector<int> path;
  // vector<int> circuit;
  stack<pair<int,int>> st;
  st.push({0,-1});
  while(!st.empty()){
    auto [node,b] = st.top();
    if(!adj[node].empty()){
      auto [adjN,bit] = adj[node].back();
      adj[node].pop_back();
      st.push(make_pair(adjN,bit));
      // path.push_back(bit);
    }else{
      // circuit.push_back(node);
      if(b!=-1) path.push_back(b);
      st.pop();
    }
  }
  // reverse(circuit.begin() , circuit.end());
  reverse(path.begin() , path.end());
  string ans(n-1,'0');
  for(auto &x : path) ans+=x+'0';
  cout<< ans <<"\n";
}