#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

// top down approach 
// int f(int n, vector<int> &a , vector<int> &dp){
//     if(n == 0) return a[n];
//     if(n < 0) return 0;
//     if(dp[n] != -1) return dp[n];

//     int pick = a[n] + f(n-2,a,dp);
//     int nopick = 0 + f(n-1,a,dp);
//     return dp[n]=max(pick,nopick);
// }

// void solve(){
//     int n; cin >> n;
//     vector<int> a(n);
//     for(int i=0 ; i<n ; i++) cin >> a[i];

//     if(n == 1){
//         cout<<a[0]<<endl;
//         return;
//     }

//     vector<int> x,y;
//     for(int i=0 ; i<n ; i++){
//         if(i != 0) x.push_back(a[i]);
//         if(i != n-1) y.push_back(a[i]);
//     }

//     vector<int> dp(n,-1) , dp2(n,-1);
//     int ans=max(f(n-2,x,dp),f(n-2,y,dp2));
//     cout<<ans<<endl;
// }

// bottom up approach
int f2(int n, vector<int> &a){
    vector<int> dp(n,-1);
    dp[0]=a[0];
    for(int i=1 ; i<n ; i++){
        int pick = a[i];
        if(i>1) pick += dp[i-2];
        int nopick=  0 + dp[i-1];
        dp[i] = max(pick, nopick);
    }
    return dp[n-1];
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    if(n == 1){
        cout<<a[0]<<endl;
        return;
    }

    vector<int> x,y;
    for(int i=0 ; i<n ; i++){
        if(i != 0) x.push_back(a[i]);
        if(i != n-1) y.push_back(a[i]);
    }

    int ans = max(f2(n-1,x), f2(n-1,y));
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


