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
    int A,B; cin >> A >> B;
    
    const int INF=1e18;
    vector<vector<int>> dp(A+1,vector<int>(B+1,INF));
    for(int i=1 ; i<=A ; i++){
        for(int j=1 ; j<=B ; j++){
            if(i == j){
                dp[i][j]=0; continue;
            }
            for(int k=1 ; k<i ; k++){
                dp[i][j]=min(dp[i][j] , dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1 ; k<j ; k++){
                dp[i][j]=min(dp[i][j] , dp[i][j-k]+dp[i][k]+1);
            }
        }
    }
    // for(auto x : dp){
        // vdebug(x)
    // }
    cout<< dp[A][B] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}