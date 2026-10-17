#include <bits/stdc++.h>

using namespace std;


#define int long long
const long long INF=1e18;
int n;
int nd;
vector<vector<int>> a;
vector<bool> vis;

int dfs(int node, int par, int d, int cnt, vector<pair<int,int>> adj[]){
  vis[node]=true;
  if(node == nd && d!=n-1) return 1e18;
  for(auto [adjN,w] : adj[node]){
    if(adjN!=par && !vis[adjN]){
      int tmp = dfs(adjN,node,d+1,cnt+w,adj);
      if(tmp != 1e18) return tmp;
    }
  }
  return cnt;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  a.resize(n,vector<int>(n));
  for(int i=0 ; i<n ; i++) for(int j=0 ; j<n ; j++) cin >> a[i][j];

  vector<pair<int,int>> adj[n];
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      if(i%2==0 && j&1){
        adj[i].push_back(make_pair(j,a[i][j]));
      }
      if(i&1 && j%2==0){
          adj[i].push_back(make_pair(j,a[i][j]));
      }
    }
  }

  nd = (n&1 ? n-1 : n);
  nd--;
  cout<<nd<<"\n";

  int mn=1e18;
  vis.resize(n);
  for(int i=0 ; i<n ; i+=2){
    fill(vis.begin(),vis.end(),false);
    mn = min(mn, dfs(i,-1,0,0,adj));
  }

  cout<< mn <<"\n";

  for(int i=0 ; i<n ; i++){
    cout<< "I: "<<i<<" -> ";
    for(auto [adjN,w] : adj[i]){
      cout<< "("<<adjN<<","<<w<<") ";
    }
    cout<<"\n";
  }


    

}