#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int N=1000;

void solve(){
    int n; cin >> n;
    vector<vector<int>> dp(N,vector<int>(N));
    for(int i=0 ; i<N ; i++) dp[i][i]=dp[i][0]=1;
    for(int i=1 ; i<N ; i++){
        for(int j=1 ; j<N ; j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    cout<< dp[n][5]+dp[n][6]+dp[n][7] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}