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

int f(int idx, int W, vector<int> &val, vector<int> &w, vector<vector<int>> &dp){
    if(idx == 0){
        if(w[0] <= W) return val[0];
        else return 0;
    }
    if(dp[idx][W] != -1) return dp[idx][W];
    
    int notake=0 + f(idx-1, W, val, w, dp);
    int take=INT_MIN;
    if(w[idx] <= W) take=val[idx] + f(idx-1, W-w[idx], val, w, dp);

    return dp[idx][W]=max(take, notake);
}

void solve(){
    int n,w; cin >> n >> w;
    vector<int> weights(n) , values(n);
    for(int i=0 ; i<n ; i++) cin >> weights[i];
    for(int i=0 ; i<n ; i++) cin >> values[i];

    // top-down approach
    // vector<vector<int>> dp(n, vector<int>(w+1,-1));
    // int ans=f(n-1, w, values, weights, dp);
    // cout<< ans <<"\n";

    vector<vector<int>> dp(n, vector<int>(w+1));

    for(int i=0 ; i<=w ; i++){
        if(weights[0]<=i) dp[0][i]=values[0];
    }
    for(int idx=1 ; idx<n ; idx++){
        for(int W=0 ; W<=w ; W++){
            int notake=dp[idx-1][W];
            int take=INT_MIN;
            if(weights[idx] <= W) take=values[idx]+dp[idx-1][W-weights[idx]];
            dp[idx][W]=max(take,notake);
        }
    }
    int ans=dp[n-1][w];
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}