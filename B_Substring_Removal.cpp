#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int MOD=998244353;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; string s; cin >> n >> s;
    int cnt1=1 , cnt2=1;
    for(int i=1 ; i<n ; i++){
        if(s[i] == s[i-1]) cnt1++;
        else break;
    }
    if(cnt1 == n){
        cout<< ((n*(n+1))%MOD * binexp(2,MOD-2))%MOD <<"\n";
        return;
    }
    for(int i=n-2 ; i>=0 ; i--){
        if(s[i] == s[i+1]) cnt2++;
        else break;
    }

    int ans=(1+cnt1+cnt2)%MOD;
    if(s[0] == s[n-1]){
        ans=(ans+(cnt1*cnt2)%MOD)%MOD;
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

