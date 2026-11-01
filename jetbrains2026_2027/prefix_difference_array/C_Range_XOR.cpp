#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  vector<int> pref(n+1);
  for(int i=0 ; i<n ; i++) pref[i+1]=pref[i]^a[i];
  for(int rep=0 ; rep<q ; rep++){
    int l,r; cin >> l >> r; l--;
    cout<< (pref[r]^pref[l]) <<"\n";
  }
}