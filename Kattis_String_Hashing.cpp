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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

#define bint __int128
const bint A=31;
const bint MOD=1e18+7;
vector<bint> p , h;

int getHash(int l, int r){
    bint ans = (h[r] - (h[l-1]*p[r-l+1]));
    return (ans%MOD + MOD)%MOD;
}

void solve(){
    string s; cin >> s;
    int q; cin >> q;

    int n=(int)s.size();
    p.resize(n+1,1);
    for(int i=1 ; i<=n ; i++){
        p[i] = (p[i-1]*A)%MOD;
    }

    h.resize(n+1);
    for(int i=1 ; i<=n ; i++){
        h[i] = ((h[i-1]*A)%MOD + s[i-1])%MOD;
    }

    for(int i=0 ; i<q ; i++){
        int l,r; cin >> l >> r;
        l++;
        cout<< getHash(l,r) <<"\n";
    }

}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}