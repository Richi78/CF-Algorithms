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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int acc=accumulate(all(a), 0LL);
    vector<vector<bool>> dp(n, vector<bool>(acc/2+1, 0));
    for(int i=0 ; i<n ; i++) dp[i][0]=true;
    dp[0][a[0]]=true;

    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<=acc/2+1 ; j++){
            bool notake=dp[i-1][j];
            bool take=false;
            if(j-a[i] >=0){
                take=dp[i-1][j-a[i]];
            }
            dp[i][j]=take||notake;
        }
    }

    int mn=1e9;
    for(int i=0 ; i<=acc/2 ; i++){
        if(dp[n-1][i])
            mn=min(mn, abs( i - ( acc - i ) ) );
    }
    cout<< mn <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}