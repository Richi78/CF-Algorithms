
#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

vector<int> dp;
const int MOD=1'000'000;

void catalan(int n){
    dp.resize(n+1);
    dp[0]=dp[1]=1;
    for(int i=2 ; i<=n ; i++){
        for(int j=0 ; j<i ; j++){
            dp[i] = (dp[i] + (dp[j] * dp[i-j-1])%MOD )%MOD;
        }
    }
}

void solve(int n){
    cout<< dp[n] <<"\n";
}

signed main(){
    FIO;
    int n;
    catalan(1005);
    while(cin >> n){
        if(n == 0) break;
        solve(n);
    }
}

