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

const int N=1e6+1;
const int MOD=1e9+7;
vector<vector<int>> dp;

void solve(){
    int n; cin >> n;
    cout<< (dp[n-1][0]+dp[n-1][1])%MOD <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    dp=vector<vector<int>>(N+1,vector<int>(2));
    dp[0][0]=dp[0][1]=1;
    
    for(int i=0 ; i<N ; i++){
        dp[i+1][0]=(dp[i+1][0]+2*dp[i][0]%MOD)%MOD;
        dp[i+1][0]=(dp[i+1][0]+dp[i][1])%MOD;
        dp[i+1][1]=(dp[i+1][1]+dp[i][0])%MOD;
        dp[i+1][1]=(dp[i+1][1]+4*dp[i][1]%MOD)%MOD;
    }    

    int tc;cin>>tc;
    while(tc--)solve();
}