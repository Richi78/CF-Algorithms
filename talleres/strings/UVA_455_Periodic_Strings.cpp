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
const int A=53;
const int MOD=998244353;
vector<int> p , h;

int getHash(int l, int r){
    int ans = (h[r] - (h[l-1]*p[r-l+1])%MOD);
    return (ans%MOD + MOD)%MOD;
}

void solve(){
    string s; cin >> s;

    int n=(int)s.size();
    h.resize(n+1);
    for(int i=1 ; i<=n ; i++){
        h[i] = ((h[i-1]*A)%MOD + s[i-1])%MOD;
    }

    for(int r=0 ; r<=n/2 ; r++){
        int l=0;
        int tmp_h=getHash(l+1,l+1+r);
        bool ok=true;
        while(l < n){
            if(l+r >= n){
                ok=false;
                break;
            }
            int tmp_r=l+r;
            int x=getHash(l+1 , tmp_r+1);
            if(tmp_h == x){
                // next group 
                l+=r+1;
            }else{
                // no periodic
                ok=false;
                break;
            }
        }
        if(ok){
            cout<< r+1 <<"\n"; return;
        }
    }
    cout<< n <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;

    p.resize(82,1);
    for(int i=1 ; i<(int)p.size() ; i++){
        p[i] = (p[i-1]*A)%MOD;
    }
    while(tc--){
        solve();
        cout<< (tc ? "\n" : "");
    }
}