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
    int p=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        if(a[i] >= 0) p++;
    }
    if(p == 0){
        cout<< *max_element(all(a)) <<"\n"; return;
    }
    int cur=0;
    int ans=0;
    for(int i=0 ; i<n ; i++){
        cur+=a[i];
        if(cur<0) cur=0;
        ans=max(ans,cur);
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}