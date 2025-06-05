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

bool f(int n, int m, map<int,bool> &dp){
    if(n == m) return dp[n]=true;
    
    if(n < m || n%3 != 0) return dp[n]=false;

    bool l=f(2*n/3, m , dp);
    bool r=f(n/3, m, dp);

    return dp[n]=l || r;
}

void solve(){
    int n,m; cin >> n >> m;
    if(n<m){
        cout<<"NO"<<endl; return;
    }
    if(n==m){
        cout<<"YES"<<endl; return;
    }

    map<int,bool> dp;

    bool ans=f(n,m,dp);
    // for(auto [x,y] : dp){
    //     debug2(x,y)
    // }
    cout<< (ans ? "YES" : "NO") <<endl;

}

signed main(){
    int tc; cin >> tc;
    while(tc--)solve();
}
