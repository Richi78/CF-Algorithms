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
int f(int n, int m, int row, int col, vector<vector<int>>& a, vector<vector<int>>& dp){
    if(row == n){
        if(col>=0 && col<=m){
            return a[row][col];
        }
    }
    if(col<0 || col>m) return -1e9;

    if(dp[row][col] != -1) return dp[row][col];

    int x=a[row][col] + f(n , m , row+1 , col-1 , a , dp);
    int y=a[row][col] + f(n , m , row+1 , col , a , dp);
    int z=a[row][col] + f(n , m , row+1 , col+1 , a , dp);

    return dp[row][col]=max(x,max(y,z));
}

void solve(){
    int n,m; cin >> n >> m;
    vector< vector<int> > a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin >> a[i][j];
    }

    // vector< vector<int> > dp(n,vector<int>(m,-1));
    // int mx=-1e9;
    // for(int i=0 ; i<m ; i++){
        // mx=max(mx, f(n-1,m-1,0,i,a,dp));
    // }
    // cout<< mx <<endl;

    // bottom up approach
    vector< vector<int> > dp(n,vector<int>(m,-1));
    for(int i=0 ; i<m ; i++){
        dp[n-1][i]=a[n-1][i];
    }

    for(int i=n-2 ; i>=0 ; i--){
        for(int j=0 ; j<m ; j++){
            int x,y,z;
            x=y=z=a[i][j];
            if(j-1>=0) x+=dp[i+1][j-1];
            else x=-1e9;
            y+=dp[i+1][j];
            if(j+1<m) z+=dp[i+1][j+1];
            else z=-1e9;
            dp[i][j]=max(x,max(y,z)); 
        }
    }
    int mx=*max_element(all(dp[0]));
    cout<< mx <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}