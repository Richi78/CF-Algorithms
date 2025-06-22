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

const int MOD=1e9+7;

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
    int n; cin >> n; 
    int cnt=0 , i=1;
    int im=binexp(2,MOD-2);
    while(i<=n){
        int factor = n / i;
        int next = ( n / factor ) + 1;
        int tmp1 = ( ( ( (next%MOD) * ((next-1)%MOD) )%MOD ) * im )%MOD;
        int tmp2 = ( ( ( (i%MOD) * ((i-1)%MOD) )%MOD ) * im )%MOD;
        cnt = (cnt + ( factor * ((tmp1-tmp2+MOD)%MOD) )%MOD )%MOD;
        i=next; 
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}