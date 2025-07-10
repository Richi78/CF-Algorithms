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
int f(int i, vector<int> &a, vector<int> &dp){
    if(i == 1){
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int l=abs(a[i-1]-a[i-1-1])+f(i-1, a, dp);
    int r=1e18;
    if(i-2 >= 1)
        r=abs(a[i-1]-a[i-1-2])+f(i-2, a, dp);

    return dp[i]=min(l,r);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // vector<int> dp(n+1,-1);
    // f(n, a, dp);

    // cout<< dp[n] <<"\n";

    //bottom up approach
    vector<int> dp(n+1,-1);
    dp[1]=0;
    for(int i=2 ; i<=n ; i++){
        int l=abs(a[i-1]-a[i-1-1]) + dp[i-1];
        int r=1e18;
        if(i >= 3)
            r=abs(a[i-1]-a[i-1-2]) + dp[i-2];
        dp[i]=min(l,r);
    }
    cout<< dp[n] <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

