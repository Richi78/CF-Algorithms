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

int f(int idx, int k, vector<int> &a, vector<vector<int>> &dp){
    if(k == 0) return 1;
    if(idx == 0) return k==a[0];
    if(dp[idx][k] != -1) return dp[idx][k];

    int notake=f(idx-1,k,a,dp);
    int take=0;
    if(a[idx]<=k) take=f(idx-1,k-a[idx],a,dp);

    return dp[idx][k]=(take+notake)%MOD;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // top-down approach
    // sort(all(a), greater<int>());
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // int ans=f(n-1, k, a, dp);

    // bottom-up approach
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0 ; i<n ; i++){
        dp[i][0]=1;
    }
    if(a[0]<=k) dp[0][a[0]]=1;
    for(int idx=1 ; idx<n ; idx++){
        for(int sum=0 ; sum<=k ; sum++){
            int notake=dp[idx-1][sum];
            int take=0;
            if(a[idx]<=sum) take=dp[idx-1][sum-a[idx]];
            dp[idx][sum]=(take+notake)%MOD;
        }
    }
    int ans=dp[n-1][k];
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