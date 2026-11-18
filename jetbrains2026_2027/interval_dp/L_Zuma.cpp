#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  vector<vector<int>> dp(n,vector<int>(n,1e9));
  for(int l=n-1 ; l>=0 ; l--){
    for(int r=l ; r<n ; r++){
      if(l == r) dp[l][r] = 1;
      else{
        if(a[l] == a[r]) dp[l][r] = l+1<=r-1 ? dp[l+1][r-1] : 1;
        for(int m=l ; m<r ; m++){
          dp[l][r] = min(dp[l][r], dp[l][m]+dp[m+1][r]);
        }
      }
    }
  }
  cout<< dp[0][n-1] <<"\n";
}