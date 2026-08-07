#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": "; for(auto f:x) cout<< f <<" "; cout<<"\n";

vector<int> a;
int n,k;
int ans=0;

pair<bool,int> dfs(int node,int parent, vector<int> adj[]){
  bool need=a[node]>k;
  int mx=-1;
  for(auto x : adj[node]){
    if(x != parent){
      pair<bool,int> tmp = dfs(x,node,adj); 
      if(tmp.first){
        need=true;
        mx=max(mx,tmp.second+1);
        ans+=2;
      }
    }
  }
  if(!need) return make_pair(false,-1);
  if(mx == -1) return make_pair(true,0);
  return make_pair(true, mx);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;
  a.resize(n);
  for(auto &x : a) cin >> x;
  vector<int> adj[n];
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pair<bool,int> tmp = dfs(0,-1,adj);
  
  cout<< (!tmp.first?0:ans-tmp.second) <<"\n";
}