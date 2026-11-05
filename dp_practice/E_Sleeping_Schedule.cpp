#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int n,h,l,r;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> h >> l >> r;
  a.resize(n);
  for(auto &x : a) cin >> x;

  vector<vector<int>> dp(n+1, vector<int>(h,-1));
  dp[0][0]=0;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<h ; j++){
      if(dp[i][j] != -1){
        int tmp1=(j+a[i])%h , tmp2=(j+a[i]-1)%h;
        dp[i+1][tmp1] = max(dp[i+1][tmp1], dp[i][j] + (tmp1>=l && tmp1<=r));
        dp[i+1][tmp2] = max(dp[i+1][tmp2], dp[i][j] + (tmp2>=l && tmp2<=r));
      }
    }
  }
  int ans=0;
  for(int i=0 ; i<h ; i++) ans=max(ans,dp[n][i]);
  cout<< ans <<"\n";
}