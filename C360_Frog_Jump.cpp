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

// in this version we can have k jumps, not only 1 or 2

int f(int n, int k, vector<int> &a, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    // vector<int> tmp(k+1,1e9);
    int mnst=INT_MAX;
    for(int i=1 ; i<=k ; i++){
        if(n-i >= 0){
            // tmp[i] = f(n-i, k, a, dp) + abs(a[n]-a[n-i]);
            int jm = f(n-i, k, a, dp) + abs(a[n]-a[n-i]);
            mnst=min(mnst,jm);
        }
    }
    // return dp[n]=*min_element(tmp.begin()+1,tmp.end());
    return dp[n]=mnst;   
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> dp(n, -1);
    int ans = f(n-1 , k , a , dp);
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}
