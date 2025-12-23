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
    int sum=0;
    vector<int> a(n);
    for(int i=0 ; i<n ;  i++){
        int u,v; cin >> u >> v;
        a[i]=u;
        sum+=v;
    }
    sort(all(a));
    int x=0;
    for(int i=0 ; i<n ; i++){
        x+=(n-i)*a[i];
    }
    cout<< sum-x <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}