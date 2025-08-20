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

#define bint __int128

bint binexp(int a, int b){
    if(b<0) return 1;
    bint ans=1;
    bint x=a;
    while(b){
        if(b&1) ans*=x;
        x*=x;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    bint a=binexp(4,n-3);
    bint b=binexp(4,n-4);
    bint ans=24*a + (n-3)*4*9*b;
    string s="";
    while(ans){
        s.push_back(ans%10+'0');
        ans/=10;
    }
    reverse(all(s));
    cout<< s <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

