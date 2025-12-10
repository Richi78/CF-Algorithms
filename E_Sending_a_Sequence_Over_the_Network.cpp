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
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];

    vector<bool> dp(n+1);
    dp[0]=true;
    for(int i=1 ; i<=n ; i++){
        if(i+a[i]<=n && dp[i-1]) dp[i+a[i]]=true;
        if(i-a[i]>=1 && dp[i-a[i]-1]) dp[i]=true;
    }
    cout<< (dp[n]?"YES":"NO") <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}