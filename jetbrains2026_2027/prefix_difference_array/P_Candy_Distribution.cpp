#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,k; cin >> n >> k;
  vector<vector<long long>> dp(n+1,vector<long long>(k+1));
  dp[0][0]=1;
  for(int i=1 ; i<=n ; i++){
    int a,b; cin >> a >> b;
    vector<long long> pref(k+2);
    for(int j=0 ; j<=k ; j++) pref[j+1]=(pref[j]+dp[i-1][j])%MOD;
    for(int j=0 ; j<=k ; j++){
      int r=j-a , l=max(0,j-b);
      if(r<l) continue;
      dp[i][j]=(pref[r+1]-pref[l]+MOD)%MOD;
    }
  }
  cout<< dp[n][k] <<"\n";
}