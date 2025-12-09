#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int N=1e5+5;

void solve(){
    int n; cin >> n;
    vector<int> freq(N);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x; 
        freq[x]++;
    }

    vector<int> dp(N);
    dp[1]=freq[1];
    for(int i=2 ; i<N ; i++){
        dp[i]=max(dp[i-1] , freq[i]*i+dp[i-2]);
    }
    cout<< dp[N-1] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}