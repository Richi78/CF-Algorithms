#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,q; cin >> n >> m >> q;
  vector<long long> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> diff(n+1);
  for(int i=0 ; i<m ; i++){
    int l,r,val; cin >> l >> r >> val; l--;
    diff[l]+=val; diff[r]-=val;
  }
  for(int i=1 ; i<=n ; i++) diff[i]+=diff[i-1];
  vector<long long> pref(n+1);
  for(int i=0 ; i<n ; i++) a[i]+=diff[i] , pref[i+1]=pref[i]+a[i];
  for(int i=0 ; i<q ; i++){
    int l,r; cin >> l >> r; l--;
    cout<< pref[r] - pref[l] <<"\n";
  }
}