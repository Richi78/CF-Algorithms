#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,q; cin >> n >> m >> q;
  vector<vector<long long>> a(n,vector<long long>(m));
  for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) cin >> a[i][j];
  vector<vector<long long>> pref(n+1, vector<long long>(m+1));
  for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) pref[i+1][j+1]=pref[i+1][j]+pref[i][j+1]-pref[i][j]+a[i][j];
  for(int i=0 ; i<q ; i++){
    int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--;
    cout<< pref[r2][c2]-pref[r2][c1]-pref[r1][c2]+pref[r1][c1] <<"\n";
  }
}