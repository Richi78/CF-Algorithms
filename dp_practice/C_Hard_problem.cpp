#include <bits/stdc++.h>

using namespace std; 

const long long INF=1e18;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<long long> a(n);
  for(auto &x : a) cin >> x;

  vector<vector<long long>> dp(n,vector<long long>(2,INF));
  dp[0][0]=0; dp[0][1]=a[0];
  string prv; cin >> prv;
  string rev_prv=prv; 
  reverse(rev_prv.begin(), rev_prv.end());
  for(int i=1 ; i<n ; i++){
    string s; cin >> s;
    string rev_s=s;
    reverse(rev_s.begin(), rev_s.end());

    if(s >= prv) dp[i][0]=min(dp[i][0],dp[i-1][0]);
    if(s >= rev_prv) dp[i][0]=min(dp[i][0],dp[i-1][1]);
    if(rev_s >= prv) dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
    if(rev_s >= rev_prv) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);

    prv=s;
    rev_prv=rev_s;
  }
  long long ans=min(dp[n-1][0],dp[n-1][1]);
  cout<< (ans == INF ? -1 : ans) <<"\n";
}