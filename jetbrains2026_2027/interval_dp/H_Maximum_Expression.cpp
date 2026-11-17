#include <bits/stdc++.h>

using namespace std;

long long op(char c, long long a, long long b){
  if(c == '+') return a+b;
  else return a*b;
}

int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  if(n == 1){
    cout<< a[0] <<"\n"; return 0;
  }
  string s; cin >> s;

  vector<vector<long long>> dp1(n, vector<long long>(n,-1e18)); // max 
  vector<vector<long long>> dp2(n, vector<long long>(n,1e18)); // min
  for(int l=n-1 ; l>=0 ; l--){
    for(int r=l ; r<n ; r++){
      if(l == r) dp1[l][r] = a[l] , dp2[l][r]=a[l];
      else{
        for(int m=l ; m<r ; m++){
          dp1[l][r] = max(dp1[l][r] , op(s[m] , dp1[l][m],dp1[m+1][r]));
          dp1[l][r] = max(dp1[l][r] , op(s[m] , dp1[l][m],dp2[m+1][r]));
          dp1[l][r] = max(dp1[l][r] , op(s[m] , dp2[l][m],dp1[m+1][r]));
          dp1[l][r] = max(dp1[l][r] , op(s[m] , dp2[l][m],dp2[m+1][r]));

          dp2[l][r] = min(dp2[l][r] , op(s[m] , dp1[l][m],dp1[m+1][r]));
          dp2[l][r] = min(dp2[l][r] , op(s[m] , dp1[l][m],dp2[m+1][r]));
          dp2[l][r] = min(dp2[l][r] , op(s[m] , dp2[l][m],dp1[m+1][r]));
          dp2[l][r] = min(dp2[l][r] , op(s[m] , dp2[l][m],dp2[m+1][r]));
        }
      }
    }
  }
  cout<< dp1[0][n-1] <<"\n";
}