#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n,k; cin >> n >> k;
  vector<int> dp(n+1);
  dp[0]=1;
  for(int i=1 ; i<=n ; i++){
    if(i == k) continue;
    for(int j=i ; j<=n ; j++){
      dp[j]+=dp[j-i];
      if(dp[j] >= MOD) dp[j]-=MOD;
    }
  }
  cout<< dp[n] <<"\n";
}