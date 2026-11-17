#include <bits/stdc++.h> 

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  vector<vector<int>> dp(n,vector<int>(n,-1));
  int mx=0;
  for(int l=n-1 ; l>=0 ; l--){
    for(int r=l ; r<n ; r++){
      if(l == r) dp[l][r] = a[l];
      else{
        for(int m=l ; m<r ; m++){
          if(dp[m+1][r]!=-1 && dp[l][m]==dp[m+1][r]) dp[l][r] = max(dp[l][r], dp[m+1][r]+1);
        }
      }
      mx=max(mx,dp[l][r]);
    }
  }
  // for(auto row : dp){
  //   for(auto e : row) cout<< e <<" ";
  //   cout<<"\n";
  // }
  cout<< mx <<"\n";
}