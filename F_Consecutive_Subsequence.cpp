#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> dp;

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]=x;
        dp[x]=dp[x-1]+1;
    }

    int k=0;
    int mx=0;
    for(auto [x,y] : dp){
        if(y>k) k=y,mx=x;
    }
    vector<int> ans;
    for(int i=n-1 ; i>=0 ; i--){
        if(a[i] == mx) ans.push_back(i+1),mx--;
    }
    reverse(all(ans));
    
    cout<< k <<"\n";
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}