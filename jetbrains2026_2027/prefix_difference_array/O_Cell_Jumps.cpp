#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n,k; cin >> n >> k;
  string s; cin >> s;
  vector<long long> dp(n) , pref(n+1);
  dp[0]=1; pref[1]=1;
  for(int i=1 ; i<n ; i++){
    if(s[i]=='#'){
      pref[i+1]=pref[i];
      continue;
    }
    dp[i] = (pref[i] - pref[max(0,i-k)] +MOD)%MOD;
    pref[i+1]=(pref[i+1]+(pref[i]+dp[i])%MOD)%MOD;
  }
  cout<< dp[n-1] <<"\n";
}