#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(k);
    for(int i=0 ; i<k ; i++) cin >> a[i];

    int ans=0;
    for(int mask = 1; mask < (1LL << k); mask++) {
        int prod = 1;
        for(int i = 0; i < k; i++) {
            if(mask & (1LL << i)) {
                if(prod > n/a[i]){
                    prod=n+1; break;
                }
                prod *= a[i];  
            }
        }
        int bits=__builtin_popcountll(mask);
        if(bits&1) ans += n / prod;
        else ans -= n / prod;
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