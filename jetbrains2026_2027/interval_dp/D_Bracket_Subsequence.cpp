#include <bits/stdc++.h>

using namespace std;

string s;

bool match(int i, int j){
  return (s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']');
}

void reconstruct(int i, int j, string &ans, vector<vector<int>> &dp){
  if(i>=j || dp[i][j]==0) return;
  if(match(i,j) && dp[i][j]==dp[i+1][j-1]+2){
    ans+=s[i];
    reconstruct(i+1,j-1,ans,dp);
    ans+=s[j];
    return;
  } 
  for(int k=i ; k<j ; k++){
    if(dp[i][j] == dp[i][k]+dp[k+1][j]){
      reconstruct(i,k,ans,dp);
      reconstruct(k+1,j,ans,dp);
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n,vector<int>(n));
  for(int i=n-1 ; i>=0 ; i--){
    for(int j=i+1 ; j<n ; j++){
      if(match(i,j)) dp[i][j] = dp[i+1][j-1] + 2;
      // else{
        for(int k=i ; k<j ; k++){
          dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
        }
      // }
    }
  }
  string ans;
  reconstruct(0,n-1,ans,dp);
  cout<< dp[0][n-1] <<"\n"<< ans <<"\n";
}
