#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int mx=n;
    int idx=0;
    while(idx<n && a[idx]==mx) idx++ , mx--;
    int idx2=idx+1;
    while(idx2<n && a[idx2]!=mx) idx2++;
    for(int i=0 ; i<idx ; i++) cout<< a[i] <<" ";
    for(int i=idx2 ; i>=idx && i<n ; i--) cout<< a[i] <<" ";
    for(int i=idx2+1 ; i<n && i<n ; i++) cout<< a[i] <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}