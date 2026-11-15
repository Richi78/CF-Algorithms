#include <bits/stdc++.h>

using namespace std;

vector<int> a;
string ans;
vector<vector<long long>> dp;
vector<vector<int>> bestK;

void reconstruct(int l, int r){
  if(l == r){
    ans+="A";
    ans+=to_string(r); 
    return;
  }
  int k = bestK[l][r];
  ans+='(';
  reconstruct(l,k);
  ans+='*';
  reconstruct(k+1,r);
  ans+=')';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  a.resize(n+1);
  for(auto &x : a) cin >> x;
  dp.assign(n+1,vector<long long>(n+1,1e18));
  bestK.assign(n+1,vector<int>(n+1));
  for(int l=n ; l>=1 ; l--){
    for(int r=l ; r<n+1 ; r++){
      if(l == r){
        dp[l][r] = 0;
        continue;
      } 
      for(int k=l ; k<r ; k++){
        long long tmp = dp[l][k] + dp[k+1][r] + 1LL*a[l-1]*a[k]*a[r];
        if(tmp < dp[l][r]){
          dp[l][r] = tmp;
          bestK[l][r] = k;
        }
      }
    }
  }
  reconstruct(1,n);
  cout<< dp[1][n] <<"\n"<< ans <<"\n";
}