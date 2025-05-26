#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

//top down approach
// int f(int n, int m, vector<vector<int>> &dp){
//     if(n < 0 ) return 0;
//     if(m < 0 ) return 0;

//     if(dp[n][m] != -1) return dp[n][m];
//     if(n==0 && m==0) return 1;

//     int l=f(n-1,m,dp);
//     int r=f(n,m-1,dp);

//     return dp[n][m]=l+r;
// }

// void solve(){
//     int n,m; cin >> n >> m;

//     vector< vector<int> > dp(n, vector<int>(m,-1));
//     int ans=f(n-1,m-1,dp);
//     cout<< ans <<endl;
// }

// bottom up approach
void solve(){
    int n,m; cin >> n >> m;

    vector< vector<int> > dp(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(i==0){
                dp[i][j]=1;
            }else if(j==0){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<< dp[n-1][m-1] << endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

