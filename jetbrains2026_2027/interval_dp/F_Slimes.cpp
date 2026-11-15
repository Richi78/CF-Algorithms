#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  vector<long long> pref(n+1);
  for(int i=0 ; i<n; i ++) pref[i+1]=pref[i]+a[i];
  vector<vector<long long>> dp(n,vector<long long>(n,1e18));  
  for(int i=n-1 ; i>=0 ; i--){
    for(int j=i ; j<n ; j++){
      if(i == j) dp[i][j]=0;
      else{
        for(int k=i ; k<j ; k++){
          dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + pref[j+1]-pref[i]);
        }
      } 
    }
  }
  // for(auto row : dp){
  //   for(auto col : row){
  //     cout<< (col==1e18?"*":to_string(col)) <<" ";
  //   }
  //   cout<<"\n";
  // }
  cout<< dp[0][n-1] <<"\n";
}