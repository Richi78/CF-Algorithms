#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<long long> a(n+2,1);
  for(int i=1 ; i<=n ; i++) cin >> a[i];
  vector<vector<long long>> dp(n+2, vector<long long>(n+2));
  for(int l=n ; l>=1 ; l--){
    for(int r=l ; r<=n ; r++){
      for(int m=l ; m<=r ; m++){
        long long left= m==l?0:dp[l][m-1];
        long long right= m==r?0:dp[m+1][r];
        dp[l][r] = max(dp[l][r], left+right+a[l-1]*a[m]*a[r+1]);
      }
    }
  }
  // for(auto row : dp){
  //   for(auto e : row) cout<< e <<" ";
  //   cout<<"\n";
  // }
  cout<< dp[1][n] <<"\n";
}