#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum=0;
    for(int i=0 ; i<n ; i++) cin >> a[i], sum+=a[i];
    vector<int> suf(n);
    suf[n-1]=-a[n-1];
    for(int i=n-2 ; i>=0 ; i--){
        suf[i]=suf[i+1]-a[i];
    }
    int ans=max(suf[1],sum);
    const int INF=1e18;
    int mx=max(a[0],-a[0]) , mn=min(a[0],-a[0]);
    for(int i=1 ; i<n-1 ; i++){
        mx+=a[i];
        mn-=a[i];
        ans=max(ans,mx+suf[i+1]);
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