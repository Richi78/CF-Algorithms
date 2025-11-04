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
    int n; cin >> n;
    vector<string> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    if(a[0][0] == '*'){
        cout<< "0\n"; return;
    }

    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][0]=1;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i+1<n && a[i+1][j] != '*'){
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            }
            if(j+1<n && a[i][j+1] != '*'){
                dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
            }
        }
    }
    cout<< dp[n-1][n-1] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}