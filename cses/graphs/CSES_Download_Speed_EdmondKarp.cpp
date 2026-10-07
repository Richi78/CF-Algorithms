#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,m;
int flow=1e18;

int bfs(int s, vector<int> &parent, vector<pair<int,int>> adj[]){
  vector<bool> vis(n);
  vis[s]=true;
  queue<pair<int,int>> q;
  q.push(make_pair(s,1e18));
  while(!q.empty()){
    auto [node, mn] = q.front();
    q.pop();
    for(auto [adjN,w] : adj[node]){
      if(!vis[adjN] && w>0){
        q.push(make_pair(adjN,min(mn,w)));
        vis[adjN]=true;
        parent[adjN]=node;
        if(adjN == n-1){
          return min(mn,w);
        }
      }
    }
  }
  return 1e18;
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
    flow=bfs(0,parent,adj);
    if(flow != 1e18) mx+=flow;
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
      for(auto &[adjN,w] : adj[parent[cur]]){
        if(adjN == cur && w>=flow){
          w-=flow;
          break;
        }
      }
    }
  }

  cout<< mx <<"\n";
}