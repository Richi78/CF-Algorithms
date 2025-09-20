#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

// brute force solution O(2^q) 
// I can optimize with dp[i][j]
// that is O(n*q), not fast enough yet
// I need to optimize to dp[i]

const int MOD=1e9+7;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

// brute force
void f(int idx, vector<int> &query, vector<int> &a, int cur, vector<int> &ans){
    int n=query.size();
    if(idx==n){
        for(int i=0 ; i<n ; i++){
            ans[i]+=a[i];
        }
        return;
    }

    // go to
    f(idx+1, query, a, query[idx]-1,ans);
    // take
    a[cur]+=query[idx];
    f(idx+1, query, a, cur,ans);
    a[cur]-=query[idx];
}

void solve(){
    int n,q; cin >> n >> q;
    
    vector<int> query(q+1);
    for (int i = 1; i <= q; i++) cin >> query[i];

    int inv2 = binexp(2, MOD-2);
    vector<int> h(q+2);
    for (int i = q; i >= 1; i--) {
        h[i] = ( (query[i] + h[i+1]) % MOD ) * inv2 % MOD;
    }

    vector<int> ans(n+1);

    for (int i = 1; i <= q; i++) {
        int fi = h[i+1] * inv2 % MOD;
        ans[query[i]] = (ans[query[i]] + fi) % MOD;
    }

    // special case table 1 gets h[1]
    ans[1] = (ans[1] + h[1]) % MOD;

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}