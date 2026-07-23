#include <bits/stdc++.h>

using namespace std;

const int MOD=998244353;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  int total_xor=0;
  for(auto &x : a) cin >> x , total_xor^=x;

  int ans= total_xor==0;
  for(int i=0; i<n ; i++){
    ans+= (total_xor^a[i])<a[i];
  }
  cout<< (n==1 ? 0 : ans) <<"\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while(tc--){
    solve();
  }
  return 0;
}