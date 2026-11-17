#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n,vector<int>(n,1e9));
  for(int l=n-1 ; l>=0 ; l--){
    for(int r=l ; r<n ; r++){
      if(l == r){
        dp[l][r] = 1;
        continue;
      }
      if(s[l] == s[r]){
        dp[l][r] = min(dp[l][r] , dp[l][r-1]);
        continue;
      } 
      for(int m=l ; m<r ; m++){
        dp[l][r] = min(dp[l][r] , dp[l][m]+dp[m+1][r]);
      }
    }
  }
  // for(auto row : dp){
  //   for(auto e : row) cout<< (e==1e9?0:e) <<" ";
  //   cout<<"\n";
  // }
  cout<< dp[0][n-1] <<"\n";
}