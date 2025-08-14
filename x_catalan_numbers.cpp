
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

void solve(){
    cout<< dp[5] <<"\n";
    int n; cin >> n;
    int C=1; // C0
    for(int i=0 ; i<n ; i++){
        C=C*2*(2*i+1)/(i+2);
    }
    cout<<C<<"\n";
}

signed main(){
    FIO;
    int n; cin >> n;
    catalan(1005);
    while(n--){
        solve();
    }
}

