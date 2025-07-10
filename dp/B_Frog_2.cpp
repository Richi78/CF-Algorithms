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

// top down approach
int f(int i, int k, vector<int> &a, vector<int> &dp){
    if(i == 1) return 0;

    if(dp[i] != -1) return dp[i];

    int mn=1e18;
    for(int j=1 ; j<=k && i-j>=1 ; j++){
        int tmp=abs(a[i-1]-a[i-1-j])+f(i-j, k, a, dp);
        uin(mn, tmp);
    }

    return dp[i]=mn;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // vector<int> dp(n+1,-1);
    // int ans=f(n, k, a, dp);
    // cout<< ans <<"\n";

    // bottom up approach
    vector<int> dp(n+1, -1);
    dp[1]=0;
    for(int i=2 ; i<=n ; i++){
        int mn=1e18;
        for(int j=1 ; j<=k && i-j>=1 ; j++){
            int tmp=abs(a[i-1]-a[i-1-j])+dp[i-j];
            uin(mn,tmp);
        }
        dp[i]=mn;
    }
    
    cout<< dp[n] <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}