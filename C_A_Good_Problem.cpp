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
    int n,l,r,k; cin >> n >> l >> r >> k;
    if(n==2) cout<<"-1\n";
    else if(n&1) cout<< l <<"\n";
    else{
        int tmp=1;
        while(tmp<=l)tmp<<=1;
        if(tmp>r)cout<<"-1\n";
        else if(k>=n-1) cout<< tmp <<"\n";
        else cout<< l <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}