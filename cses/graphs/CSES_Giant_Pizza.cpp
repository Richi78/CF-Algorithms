#include <bits/stdc++.h>

using namespace std;

stack<int> st;
vector<bool> vis;
vector<int> a;
int component_number=0;

void dfs1(int node, vector<int> adj[]){
  vis[node]=true;
  for(auto adjN : adj[node]) if(!vis[adjN]) dfs1(adjN, adj);
  st.push(node);
}

void dfs2(int node, vector<int> adj[]){
  vis[node]=true;
  a[node]=component_number;
  for(auto adjN : adj[node]) if(!vis[adjN]) dfs2(adjN, adj);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<int> adj[2*m];
  for(int i=0 ; i<n ; i++){
    char t1,t2; int v1,v2; cin >> t1 >> v1 >> t2 >> v2;
    v1--; v2--;
    int a=2*v1 + (t1=='-');
    int b=2*v2 + (t2=='-');
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
  }

  vis.resize(2*m);
  for(int i=0 ; i<2*m ; i++) if(!vis[i]) dfs1(i,adj);

  vector<int> adjT[2*m];
  for(int i=0 ; i<2*m ; i++){
    vis[i]=false;
    for(auto adjN : adj[i]) adjT[adjN].push_back(i);
  }

  a.resize(2*m);
  while(!st.empty()){
    int node = st.top();
    st.pop();
    if(!vis[node]){
      component_number++;
      dfs2(node,adjT);
    }
  }

  vector<char> ans(m);
  for(int i=0 ; i<m ; i++){
    if(a[2*i] == a[2*i+1]){
      cout<<"IMPOSSIBLE\n"; return 0;
    }
    if(a[2*i] > a[2*i+1]) ans[i] = '+';
    else ans[i] = '-';
  }
  for(auto &x : ans) cout<< x <<" ";
  cout<<"\n";
}