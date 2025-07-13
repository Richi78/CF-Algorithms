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
bool f(int idx, int k, vector<int> &a, vector<vector<int>> &dp){
    if(k==0) return true;
    else if(k<0) return false;

    if(idx == 0) return a[0]==k;

    if(dp[idx][k] != -1) return dp[idx][k];

    int take=f(idx-1, k-a[idx], a, dp);
    int notake=f(idx-1, k, a, dp);

    return dp[idx][k]=take || notake;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // cout<< f(n-1, k, a, dp) <<"\n";

    // bottom up approach
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0 ; i<n ; i++) dp[i][0]=true;
    dp[0][a[0]]=true;
    for(int i=1 ; i<n ; i++){
        for(int target=1 ; target<=k ; target++){
            bool notake=dp[i-1][target];
            bool take=false;
            if(a[i] <= target){
                take=dp[i-1][target-a[i]];
            }
            dp[i][target]=take||notake; 
        }
    }

    // for(auto x : dp){
    //     vdebug(x)
    // }

    cout<< dp[n-1][k] <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}