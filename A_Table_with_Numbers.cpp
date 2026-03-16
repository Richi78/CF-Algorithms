#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
  int n,h,l; cin >> n >> h >> l;
  if(h > l) swap(h,l);
  int cnt_h=0 , cnt_l=0;
  for(int i=0 ; i<n ; i++){
    int x; cin >> x;
    if(x <= h) cnt_h++;
    if(x <= l) cnt_l++;
  }
  cout << min(cnt_h, cnt_l/2) << "\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}