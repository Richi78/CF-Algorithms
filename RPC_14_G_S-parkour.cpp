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
    for(int i=0 ; i<n ; i++) cin >> a[i];
    vector<int> aa(n);
    for(int i=0 ; i+1<n ; i++){
        if(a[i+1] > a[i]) aa[i]=1;
        else aa[i]=-1;
    }
    map<int,int> mp;
    mp[0]=1;
    int ans=n;
    int pref=0;
    for(int i=0 ; i<n-1 ; i++){
        pref+=aa[i];
        ans+=mp[pref];
        mp[pref]++;
        debug1(ans)
    }
    cout << ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}