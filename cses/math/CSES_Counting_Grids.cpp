#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD=1e9+7;

int binexp(int a, int b, int mod=MOD){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    int ans=0;
    if(n&1){
        ans = ( ans + binexp(2 , n*n%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , (n*n+3)/4%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , (n*n+3)/4%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , (n*n+1)/2%(MOD-1) ) )%MOD;
    }else{
        ans = ( ans + binexp(2 , n*n%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , n*n/4%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , n*n/4%(MOD-1) ) )%MOD;
        ans = ( ans + binexp(2 , n*n/2%(MOD-1) ) )%MOD;
    }
    ans=ans*binexp(4,MOD-2)%MOD;
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