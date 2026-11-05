#include <bits/stdc++.h>

using namespace std;

const int MOD=1e8;
long long dp[105][105][2][15]={};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n1,n2,k1,k2; cin >> n1 >> n2 >> k1 >> k2;

  dp[1][0][0][1]=1;
  dp[0][1][1][1]=1;
  for(int i=0 ; i<=n1 ; i++){
    for(int j=0 ; j<=n2 ; j++){
      for(int cnt=0 ; cnt<=k1 ; cnt++){ // last was 0
        if(i+1<=n1 && cnt+1<=k1) dp[i+1][j][0][cnt+1] = (dp[i+1][j][0][cnt+1] + dp[i][j][0][cnt]) %MOD;
        if(j+1 <= n2) dp[i][j+1][1][1] = (dp[i][j+1][1][1] + dp[i][j][0][cnt]) %MOD;
      }
      for(int cnt=0 ; cnt<=k2 ; cnt++){ // last was 1
        if(i+1 <= n1) dp[i+1][j][0][1] = (dp[i+1][j][0][1] + dp[i][j][1][cnt]) %MOD;
        if(j+1<=n2 && cnt+1<=k2) dp[i][j+1][1][cnt+1] = (dp[i][j+1][1][cnt+1] + dp[i][j][1][cnt]) %MOD;
      }
    }
  }
  long long ans=0;
  for(int i=0 ; i<=k1 ; i++) ans = (ans + dp[n1][n2][0][i])%MOD;
  for(int i=0 ; i<=k2 ; i++) ans = (ans + dp[n1][n2][1][i])%MOD;
  cout<< ans <<"\n";
}