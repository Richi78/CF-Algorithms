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

int l,r; 
int cc , cn , ce; 
int c , n , e; 

long double f(int ch, int no, int ex, vector<vector<vector<long double>>> &dp){

    if(dp[ch][no][ex] != -1.0) return dp[ch][no][ex];

    int cur=(c-ch)*cc+(n-no)*cn+(e-ex)*ce;

    if(l <= cur && cur <= r){
        return dp[ch][no][ex] = 1.0;
    }

    int rem=ch+no+ex;
    if(rem == 0){
        if(l<=cur && cur<=r) return dp[ch][no][ex]=1.0;
        return dp[ch][no][ex]=0.0;
    }

    int mn=1e18;
    if(ch>0) mn=min(mn,cc);
    if(no>0) mn=min(mn,cn);
    if(ex>0) mn=min(mn,ce);
    if(mn!=1e18 && cur+mn>r){
        if(l<=cur && cur<=r) return dp[ch][no][ex]=1.0;
        return dp[ch][no][ex]=0.0;
    }
    
    long double tmp=0.0;
    if(ch>=1){
        long double p_c=ch/(rem*1.0);
        tmp+=f(ch-1, no, ex , dp) * p_c;
    }
    if(no>=1){
        long double p_n=no/(rem*1.0);
        tmp+=f(ch, no-1, ex , dp) * p_n;
    }
    if(ex>=1){
        long double p_e=ex/(rem*1.0);
        tmp+=f(ch, no, ex-1 , dp) * p_e;
    }

    return dp[ch][no][ex]=tmp;
}

void solve(){
    cin >> l >> r;
    cin >> cc >> cn >> ce;
    cin >> c >> n >> e;

    cout<< setprecision(10) << fixed;

    vector<vector<vector<long double>>> dp(c+1, vector<vector<long double>>(n+1,vector<long double>(e+1,-1.0)));

    long double ans=f(c, n, e, dp);

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