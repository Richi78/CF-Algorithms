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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    vector<int> pref(n+1);
    for(int i=1 ; i<=n ; i++){
        pref[i]=pref[i-1]+b[i-1];
    }
    sort(all(a));
    long long ans=0;
    for(int i=0 ; i<n ; i++){
        long long x=a[i];
        long long num=n-i;
        int r=upper_bound(all(pref), num) - pref.begin();
        ans=max(ans,x*(r-1));
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}