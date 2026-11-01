#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> pref(n+1) , i_pref(n+1);
  for(int i=0 ; i<n ; i++) pref[i+1]=pref[i]+a[i] , i_pref[i+1]=i_pref[i]+1LL*(i+1)*a[i];
  for(int i=0 ; i<q ; i++){
    int l,r; cin >> l >> r; l--;
    cout<< i_pref[r]-i_pref[l]-l*(pref[r]-pref[l]) <<"\n";
  }
}