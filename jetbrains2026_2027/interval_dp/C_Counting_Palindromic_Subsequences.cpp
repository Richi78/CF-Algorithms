#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n = s.size();
  vector<vector<long long>> dp(n, vector<long long>(n));
  for(int i=n-1 ; i>=0 ; i--){
    for(int j=i ; j<n ; j++){
      if(i == j){
        dp[i][j] = 1;
      }else if(s[i] == s[j]){
        dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
      }else{
        dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
      }
      dp[i][j] = (dp[i][j]+MOD)%MOD;
    }
  }
  cout<< dp[0][n-1] <<"\n";
}