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
int f(int n, int row, int col, vector<vector<int>> &a, vector<vector<int>> &dp){
    if(row == n) return a[row][col];

    if(dp[row][col] != -1) return dp[row][col];

    int l=a[row][col] + f(n , row+1 , col , a , dp);
    int r=a[row][col] + f(n , row+1 , col+1 , a , dp);

    return dp[row][col]=min(l,r);
}

void solve(){
    int n; cin >> n;
    vector< vector<int> > a;
    for(int i=1 ; i<=n ; i++){
        vector<int> tmp(i);
        for(int j=0 ; j<i ; j++){
            cin >> tmp[j];
        }
        a.push_back(tmp);
    }
    
    // vector< vector<int> > dp;
    // for(int i=1 ; i<=n ; i++){
        // dp.push_back(vector<int>(i,-1));
    // }

    // int ans=f(n-1,0,0,a,dp);

    // cout<< ans <<endl;

    // bottom up approach
    vector< vector<int> > dp(n,vector<int>(n));

    for(int i=0 ; i<n ; i++){
        dp[n-1][i]=a[n-1][i];
    }

    for(int i=n-2; i>=0 ; i--){
        for(int j=0 ; j<=i ; j++){
            int l=a[i][j]+dp[i+1][j];
            int r=a[i][j]+dp[i+1][j+1];
            dp[i][j]=min(l,r);
        }
    }
    cout<< dp[0][0] <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

