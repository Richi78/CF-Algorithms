#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int MOD=1e9+7;

// top down approach
int f(int idx, vector<int> &dp){
    if(idx==0) return 1;

    if(dp[idx] != -1) return dp[idx];

    int cnt=0;
    for(int i=1; i<=6 && idx-i>=0 ; i++){
        cnt= (cnt+f(idx-i, dp))%MOD;
    }

    return dp[idx]=cnt;
}

void solve(){
    int n; cin >> n;
    
    // vector<int> dp(n+1,-1);
    // int ans=f(n, dp);
    // cout<< ans <<"\n";

    // bottom up approach
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=6 && i-j>=0; j++){
            dp[i]= (dp[i]+dp[i-j])%MOD;
        }
    }
    vdebug(dp)
    cout<< dp[n] <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}