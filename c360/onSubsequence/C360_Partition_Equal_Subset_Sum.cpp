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
bool f(int idx, int target, vector<int> &a, vector<vector<int>> &dp){
    if(target == 0) return true;
    else if(target < 0) return false;

    if(idx == 0) return a[idx]==target;

    if(dp[idx][target] != -1) return dp[idx][target];

    bool take=f(idx-1, target-a[idx], a , dp);
    bool notake=f(idx-1, target, a, dp);

    return dp[idx][target]=take || notake;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int acc=accumulate(all(a), 0LL);
    
    if(acc&1){
        cout<<"false\n"; return;
    }

    // vector<vector<int>> dp(n,vector<int>(acc/2+1,-1));
    // bool ans=f(n-1, acc/2, a, dp);
    // cout<< (ans?"true":"false") <<"\n";
    
    // bottom up approach
    vector<vector<bool>> dp(n,vector<bool>(acc/2+1,0));

    for(int i=0 ; i<n ; i++) dp[i][0]=true;
    dp[0][a[0]]=true;
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<=acc/2 ; j++){
            bool notake=dp[i-1][j];
            bool take=false;
            if(j-a[i] >= 0)
                take=dp[i-1][j-a[i]];
            dp[i][j]=take||notake;
        }
    }

    cout<< (dp[n-1][acc/2]?"true":"false") <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}