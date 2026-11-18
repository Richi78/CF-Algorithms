#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  long long sum=0;
  for(int i=0; i <n ; i++) cin >> a[i] , sum+=a[i];
  vector<vector<long long>> dp(n,vector<long long>(n,-1e18));
  for(int l=n-1 ; l>=0 ; l--){
    for(int r=l ; r<n ; r++){
      if(r == l) dp[l][r] = a[l];
      else dp[l][r] = max(a[l]-dp[l+1][r] , a[r]-dp[l][r-1]);
    }
  }
  cout<< 1LL*(sum+dp[0][n-1])/2 <<"\n";
}