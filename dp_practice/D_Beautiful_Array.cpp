#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  long long n,x; cin >> n >> x;
  vector<long long> a(n);
  for(auto &y : a) cin >> y;
  
  long long ans=0;
  // dp[idx][0,1,2] 0->initialize , 1->continueBlock, 2->endBlock
  vector<vector<long long>> dp(n+1,vector<long long>(3));
  for(int i=0 ; i<n ; i++){
    dp[i+1][0]=max(0LL, dp[i][0]) + a[i];
    dp[i+1][1]=max({0LL, dp[i][0] , dp[i][1]}) + a[i]*x;
    dp[i+1][2]=max({0LL, dp[i][1] , dp[i][2]}) + a[i];
    ans=max({ans , dp[i+1][0] , dp[i+1][1] , dp[i+1][2]});
  }
  cout << ans <<"\n";
}