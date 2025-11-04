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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    vector<vector<int>> dp(n,vector<int>(m+1));
    
    if(a[0] == 0){
        for(int i=0 ; i<=m ; i++) dp[0][i]=1;
    }else{
        dp[0][a[0]]=1;
    }

    for(int i=0 ; i<=n-2 ; i++){
        for(int last=1 ; last<=m ; last++){
            for(int y : {last-1,last,last+1}){
                if(1<=y && y<=m){
                    // if not valid continue
                    if(a[i+1] != 0 && a[i+1] != y) continue;
                    dp[i+1][y]=(dp[i+1][y]+dp[i][last])%MOD;
                }
            }
        }
    }
    int ans=0;
    for(int i=1 ; i<=m ; i++){
        ans=(ans+dp[n-1][i])%MOD;
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