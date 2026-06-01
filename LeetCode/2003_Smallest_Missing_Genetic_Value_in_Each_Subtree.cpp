// parents -1 0 0 2
// nums 1 2 3 4
// ans 5 1 1 1
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+7;
vector<bool> mex;
vector<bool> vis;
vector<int> ans;

void dfs(vector<int> adj[], vector<int> &nums, int node){
  vis[node]=true;
  mex[nums[node]]=false;
  for(auto x : adj[node]){
    if(!vis[x]){
      dfs(adj,nums,x);
    }
  }
}

void solve(){
  int n; cin >> n;
  vector<int> parents(n) , nums(n);
  for(auto &x : parents) cin >> x;
  for(auto &x : nums) cin >> x;

  vector<int> adj[n];
  for(int i=1 ; i<n ; i++){
    adj[parents[i]].push_back(i);
  }

  mex.resize(N,true);
  vis.resize(n+1,false);
  ans.resize(n,1);
  int cur = -1;
  int new_mex=1;
  for(int i=0 ; i<n ; i++){
    if(nums[i] == 1){
      cur=i; break;
    }
  }

  while(cur != -1){
    dfs(adj, nums, cur);

    while(!mex[new_mex]){
      new_mex++;
    }
    ans[cur]=new_mex;
    
    cur=parents[cur];
  }


  //return ans;
  for(auto x : ans) cout<< x <<" ";
}

int main(){
  solve();
}