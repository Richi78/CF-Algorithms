#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(all(a));
    a.erase(unique(all(a)) , a.end());
    vector<int> dp(n+1 , 1e9);
    for(auto x : a){
        dp[x]=1;
        for(int i=2 ; i*x<=n ; i++) dp[i*x]=min(dp[i*x],dp[i]+1);
    }
    for(int i=1 ; i<=n ; i++){
        cout<< (dp[i]==1e9?-1:dp[i]) <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}