#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
vector<bool> removed;
vector<int> a,sz,depth;
vector<vector<int>> adj;
long long ans=0;

void dfs(int node, int par){
  sz[node]=1;
  for(auto adjN : adj[node])if(adjN!=par && !removed[adjN]){
    dfs(adjN,node);
    sz[node]+=sz[adjN];
  }
}

int find_centroid(int node, int par, int len){
  for(auto adjN : adj[node])if(adjN!=par && !removed[adjN]){
    if(sz[adjN]>len/2) return find_centroid(adjN,node,len);
  }
  return node;
}

void dfs2(int node, int par, int d, int mx, vector<pair<int,int>> &mx_dp){
  mx_dp.emplace_back(max(mx,a[node]),d);
  for(auto adjN : adj[node])if(adjN!=par && !removed[adjN]){
    dfs2(adjN,node,d+1,max(mx,a[node]),mx_dp);
  }
}

long long calculate(vector<pair<int,int>> &mx_dp){
  sort(mx_dp.begin(),mx_dp.end());
  long long sum_d=0;
  long long res=0;
  for(int j=0 ; j<mx_dp.size() ; j++){
    auto [mx,d] = mx_dp[j];

    long long tmp= (1LL*mx * ( (1LL*d*j%MOD + sum_d)%MOD ))%MOD;
    res = (res + tmp)%MOD;
    sum_d = (sum_d + d) %MOD;
  }
  return res;
}

void solve_centroid(int node){
  vector<pair<int,int>> mx_dp;
  mx_dp.emplace_back(a[node],0);
  for(auto adjN : adj[node])if(!removed[adjN]){
    vector<pair<int,int>> sub_tree;
    dfs2(adjN,node,1,a[node],sub_tree);
    ans = (ans - calculate(sub_tree)+MOD)%MOD; 
    mx_dp.insert(mx_dp.end(),sub_tree.begin(),sub_tree.end());
  }
  ans = (ans + calculate(mx_dp))%MOD;
}

void decompose(int node,int par){
  dfs(node,par); 
  int c=find_centroid(node,-1,sz[node]);

  solve_centroid(c);

  removed[c]=true;

  for(auto adjN : adj[c])if(!removed[adjN]){
    decompose(adjN,c);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;
  adj.resize(n);
  for(int i=0 ; i<n-1 ; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  sz.resize(n); depth.resize(n);
  removed.resize(n);
  decompose(0,-1);

  cout<< ans <<"\n";
}