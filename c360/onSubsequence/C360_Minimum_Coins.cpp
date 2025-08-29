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

vector<int> coins={1,2,5,10,20,50,100,500,1000};
// vector<vector<int>> dp;
vector<int> prv,cur;

vector<vector<int>> dp;
int f(int idx, int p, vector<vector<int>> &dp){
    if(idx == 0){
        if(p%coins[0] == 0) return p/coins[0];
        else return 1e9;
    }
    if(dp[idx][p] != -1) return dp[idx][p];

    int notake=0+f(idx-1, p, dp);
    int take=INT_MAX;
    if(coins[idx] <= p) take=1+f(idx, p-coins[idx], dp);

    return dp[idx][p]=min(take,notake);
}

void solve(){
    int p; cin >> p;
    int n=coins.size();

    // top-down approach
    // dp=vector<vector<int>>(n,vector<int>(p+1,-1));
    // cout<< f(n-1,p,dp) <<"\n";

    //bottom-up approach
    prv.resize(p+1); cur.resize(p+1);
    for(int T=0 ; T<=p ; T++){
        if(T%coins[0] == 0) prv[T]=T/coins[0];
        else prv[T]=1e9;
    }
    for(int idx=1 ; idx<n ; idx++){
        for(int T=0 ; T<=p ; T++){
            int notake=prv[T];
            int take=INT_MAX;
            if(coins[idx]<=T) take=1+cur[T-coins[idx]];
            cur[T]=min(take,notake);
        }
        prv=cur;
    }
    cout<< prv[p] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}