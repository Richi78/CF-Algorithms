#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,m;
int flow=1e18;

bool dfs(int node, vector<int> &parent, vector<bool> &vis, vector<pair<int,int>> adj[]){
  vis[node] = true;
  if(node == n-1) return true;
  for(auto [adjN,w] : adj[node]){
    if(!vis[adjN] && w>0){
      parent[adjN]=node;
      bool tmp=dfs(adjN,parent,vis,adj);
      if(tmp) {
        flow=min(flow,w);
        return true;
      }
    }
  }
  return false;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  vector<pair<int,int>> adj[n];
  for(int i=0 ; i<m ; i++){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,0);
  }

  int mx=0;
  while(true){
    vector<int> parent(n,-1);
    vector<bool> vis(n);
    flow=1e18;
    dfs(0,parent,vis,adj);

    if(flow!=1e18) mx+=flow;
    else break;

    for(int cur=n-1 ; cur!=0 ; cur=parent[cur]){
      int par=-1;
      for(auto &[adjN,w] : adj[cur]){
        if(adjN == parent[cur]){
          w+=flow;
          par=adjN;
          break;
        } 
      }
      for(auto &[adjN,w] : adj[par]){
        if(adjN == cur && w >= flow){
          w-=flow;
          break;
        }
      }
    }
  }

  cout<< mx <<"\n";
}