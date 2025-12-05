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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];

    int mx=0 , mn=0;
    for(int i=0 ; i<n ; i++){
        int tmp1=max(mx-a[i],b[i]-mx);
        int tmp2=max(mn-a[i], b[i]-mn); 
        int tmp3=min(mx-a[i],b[i]-mx);
        int tmp4=min(mn-a[i],b[i]-mn);
        mx=max({tmp1,tmp2,tmp3,tmp4});
        mn=min({tmp1,tmp2,tmp3,tmp4});
    }
    cout<< mx <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}