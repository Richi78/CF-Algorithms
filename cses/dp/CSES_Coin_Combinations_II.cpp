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

const int MOD=1e9+7;

void solve(){
    int n,x; cin >> n >> x;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> dp(x+1);
    dp[0]=1;
    for(auto coin : a){
        for(int s=0 ; s<x ; s++){
            if(s+coin <= x){
                dp[s+coin]=(dp[s+coin]+dp[s])%MOD;
            }
        }
    } 
    cout<< dp[x] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}