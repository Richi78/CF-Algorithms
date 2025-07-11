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

// top down approach
// int f(int day, int last, vector<vector<int>> &a, vector<vector<int>> &dp){
//     int mx=0;
//     if(day == 0){
//         for(int i=0 ; i<3 ; i++){
//             if(i != last) mx=max(mx, a[day][i]);
//         }
//         return mx;
//     }

//     if(dp[day][last] != -1) return dp[day][last];

//     for(int i=0 ; i<3 ; i++){
//         if(i != last){
//             int p = a[day][i] + f(day-1 , i , a , dp);
//             mx=max(mx,p);
//         }
//     }
    
//     return dp[day][last]=mx;
// }

// void solve(){
//     int n; cin >> n;
//     vector< vector<int> > a(n, vector<int>(3));
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<3 ; j++){
//             cin >> a[i][j];
//         }
//     }

//     vector< vector<int> > dp(n, vector<int>(4,-1));
//     int ans=f(n-1 , 3 , a , dp);
//     cout << ans << endl;

// }

// bottom up approach

void solve(){
    int n; cin >> n;
    vector< vector<int> > a(n, vector<int>(3));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> a[i][j];
        }
    }

    vector< vector<int> > dp(n,vector<int>(4,0));
    dp[0][0] = max(a[0][1],a[0][2]);
    dp[0][1] = max(a[0][0],a[0][2]);
    dp[0][2] = max(a[0][0],a[0][1]);
    dp[0][3] = max(a[0][0],max(a[0][1],a[0][2]));

    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<4 ; j++){
            int mx=0;
            for(int k=0 ; k<3 ; k++){
                if(k != j){
                    int p=a[i][k]+dp[i-1][k];
                    mx=max(mx,p);
                }
            }            
            dp[i][j]=mx;
        }
    }
    cout << dp[n-1][3] <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


