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
int f(int idx, int last, vector<vector<int>> &a, vector<vector<int>> &dp){
    if(idx == 0){
        int mx=-1;
        for(int i=0 ; i<3 ; i++){
            if(i != last) uax(mx,a[idx][i]);
        }
        return mx;
    }

    if(dp[idx][last] != -1) return dp[idx][last];

    int mx=-1;
    for(int i=0 ; i<3 ; i++){
        if(i != last){
            int tmp=a[idx][i]+f(idx-1, i, a, dp);
            uax(mx, tmp);
        }
    }

    return dp[idx][last]=mx;
}

void solve(){
    int n; cin >> n;
    vector< vector<int> > a(n, vector<int>(3));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> a[i][j];
        }
    }

    // vector<vector<int>> dp(n, vector<int>(4,-1));
    // int ans=f(n-1, 3, a, dp);

    // cout<< ans <<"\n";

    // bottom up approach
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<3 ; j++){
            for(int k=0 ; k<3 ; k++){
                if(j != k){
                    dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][k]);
                }
            }
        }
    }

    cout<< *max_element(all(dp[n-1]))<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}