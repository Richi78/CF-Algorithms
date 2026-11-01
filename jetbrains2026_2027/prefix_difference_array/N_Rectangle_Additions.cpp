#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,q; cin >> n >> m >> q;
  vector<vector<long long>> a(n, vector<long long>(m));
  for(int i=0 ; i<n ; i++)for(int j=0 ; j<m ; j++) cin >> a[i][j];
  vector<vector<long long>> pref(n+2,vector<long long>(m+2));
  for(int i=0 ; i<q ; i++){
    long long r1,c1,r2,c2,val; cin >> r1 >> c1 >> r2 >> c2 >> val; r2++; c2++;
    pref[r1][c1]+=val; pref[r1][c2]-=val; pref[r2][c1]-=val; pref[r2][c2]+=val;
  }
  for(int i=0 ; i<n ; i++)for(int j=0 ; j<m ; j++) pref[i+1][j+1]+=pref[i][j+1]+pref[i+1][j]-pref[i][j];
  for(int i=0 ; i<n ; i++)for(int j=0 ; j<m ; j++) a[i][j]+=pref[i+1][j+1];
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m ; j++) cout<< a[i][j] <<" ";
    cout<<"\n";
  }
}