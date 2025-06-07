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
    int n,c; cin >> n >> c;
    vector<int> a(n-1) , b(n-1);

    for(int i=0 ; i<n-1 ; i++) cin >> a[i];
    for(int i=0 ; i<n-1 ; i++) cin >> b[i];

    vector< vector<int> > dp(n, vector<int>(2));
    dp[0][0] = 0; dp[0][1]=c;
    cout<< min(dp[0][0],dp[0][1])<< " ";
    for(int i=1 ; i<n ; i++){
        dp[i][0] = min(dp[i-1][0]+a[i-1] , dp[i-1][1]+a[i-1]);
        dp[i][1] = min(dp[i-1][0]+b[i-1]+c , dp[i-1][1]+b[i-1]);
        cout<< min(dp[i][0] , dp[i][1])<< " ";
    }

    // for(auto x : dp){
        // cout<< min(x[0],x[1]) <<" ";
    // }
    cout<<endl;
}

signed main(){
    // FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}