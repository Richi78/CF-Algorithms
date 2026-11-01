#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> nxt;
int best_lca=-1 , branch1=-1, branch2=-1;
int diameter=0;

int dfs(int node, int par){
  int best1=0 , best2=0;
  int c1=-1 , c2=-1;

  for(auto adjN : adj[node])if(adjN!=par){
    int tmp = 1+dfs(adjN, node);
    if(tmp > best1){
      best2=best1; c2=c1;
      best1=tmp; c1=adjN;
    }else if(tmp> best2){
      best2=tmp; c2=adjN;
    }
  }

  if(best1+best2 > diameter){
    diameter = max(diameter, best1+best2);
    best_lca=node;
    branch1=c1;
    branch2=c2;
  }

  nxt[node]=c1;
  return best1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  nxt.resize(n,-1);
  dfs(0,-1);

  vector<int> left , right;
  for(int cur=branch1 ; cur!=-1 ; cur=nxt[cur]){
    left.push_back(cur);
  }
  reverse(left.begin(), left.end());
  for(int cur=branch2 ; cur!=-1 ; cur=nxt[cur]){
    right.push_back(cur);
  }
  left.push_back(best_lca);
  left.insert(left.end(), right.begin(), right.end());

  cout<< diameter <<"\n";
  for(auto &x : left) cout<< x+1 <<" ";
  cout<<"\n";
}