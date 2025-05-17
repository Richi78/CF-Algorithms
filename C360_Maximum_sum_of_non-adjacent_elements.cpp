#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

// top down approach
int f(int n, vector<int> &a, vector<int> &dp){
    if(n == 0) return a[n];
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    int pick=a[n] + f(n-2, a , dp);
    int nopick=0 + f(n-1, a , dp);
    return dp[n]=max(pick,nopick);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> dp(n,-1);
    int ans = f(n-1 , a , dp);
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

