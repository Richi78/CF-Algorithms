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
int f(int n, int m, vector<vector<int>> &a, vector<vector<int>> &dp){
    if(n<0 || m<0) return 1e9;

    if(dp[n][m] != -1) return dp[n][m];
    if(n==0 && m==0) return a[n][m];

    int l=f(n-1,m,a,dp);
    int r=f(n,m-1,a,dp);

    return dp[n][m]=min(a[n][m]+l , a[n][m]+r);
}

void solve(){
    int n,m; cin >> n >> m;
    vector< vector<int> > a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin >>a[i][j];
    }

    // vector< vector<int> > dp(n,vector<int>(m,-1));
    // int ans=f(n-1,m-1,a,dp);
    // cout<< ans <<endl;

    //bottom up approach
    vector< vector<int> > dp(n+1,vector<int>(m+1,1e9));
    dp[1][1]=a[0][0];

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(i==1 && j==1) continue;
            int x=a[i-1][j-1];
            dp[i][j]=min(x+dp[i-1][j] , x+dp[i][j-1]);
        }
    }
    cout<< dp[n][m] <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}