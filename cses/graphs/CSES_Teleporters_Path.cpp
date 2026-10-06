#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<int> adj[n];
  vector<int> indeg(n) , outdeg(n);
  for(int i=0 ; i<m ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    outdeg[u]++; indeg[v]++;
  }
  int start=-1 , end=-1 , odd=0;
  for(int i=0 ; i<n ; i++){
    if(outdeg[i]-indeg[i] == 1){
      odd++; 
      start=i;
    }else if(indeg[i]-outdeg[i] == 1){
      odd++;
      end=i;
    }else if(abs(indeg[i]-outdeg[i]) > 1){
      cout<<"IMPOSSIBLE\n"; return 0;
    }
  }
  if(odd!=0 && odd!=2){
    cout<<"IMPOSSIBLE\n"; return 0;
  }

  if(odd == 0) start=0;
  if(start!=0 || end!=n-1){
    cout<<"IMPOSSIBLE\n"; return 0;
  }

  vector<int> circuit;
  stack<int> st;
  st.push(start);
  while(!st.empty()){
    int node = st.top();
    if(!adj[node].empty()){
      int adjN=adj[node].back();
      adj[node].pop_back();
      st.push(adjN);
    }else{
      circuit.push_back(node);
      st.pop();
    }
  }
  reverse(circuit.begin() , circuit.end());

  if(circuit.size() != m+1){
    cout<<"IMPOSSIBLE\n"; return 0;
  }

  for(auto &x : circuit) cout<< x+1 <<" ";
  cout<<"\n";
}