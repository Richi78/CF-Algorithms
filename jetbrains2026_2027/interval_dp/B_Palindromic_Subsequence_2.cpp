#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n,vector<int>(n));
  for(int i=n-1 ; i>=0 ; i--){
    for(int j=i ; j<n ; j++){
      if(i == j) dp[i][j]=1;
      else if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
      else dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
    }
  }
  string l , r;
  for(int i=0 , j=n-1 ; i<=j ; ){
    if(i == j){
      l+=s[i]; break;
    }
    if(s[i] == s[j]){
      l+=s[i]; r+=s[j];
      i++; j--;
    }else if(dp[i+1][j] >= dp[i][j-1]) i++;
    else j--;
  }
  reverse(r.begin() , r.end());
  cout<< dp[0][n-1] <<"\n"<< l+r <<"\n";
}