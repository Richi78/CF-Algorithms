#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<vector<long long>> dp;


long long f(int l, int r){
  if(l+1 == r) return dp[l][r]=0;
  if(dp[l][r] != 1e18) return dp[l][r];
  for(int i=l+1 ; i<r ; i++){
    dp[l][r]=min(dp[l][r],a[r]-a[l]+f(l,i)+f(i,r));
  }
  return dp[l][r];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int l,n; cin >> l >> n;
  a.push_back(0);
  for(int i=0 ; i<n ; i++){
    int x; cin >> x; a.push_back(x);
  }
  a.push_back(l);
  int sz=a.size();
  dp.assign(sz,vector<long long>(sz,1e18));
  for(int l=sz-1 ; l>=0 ; l--){
    for(int r=l+1 ; r<sz ; r++){
      if(l+1 == r){
        dp[l][r]=0;
        continue;
      } 
      for(int m=l+1 ; m<r ; m++){
        dp[l][r]=min(dp[l][r],a[r]-a[l]+dp[l][m]+dp[m][r]);
      }
    }
  }
  cout<< dp[0][sz-1] <<"\n";
  // cout<< f(0,sz-1) <<"\n";
}