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

// brute force solution O(2^n) 
// I can optimize with dp[i][j]
// that is O(n^2), not fast enough yet
// we need to optimize to dp[i]

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
    
    vector<int> que(q);
    for(int i=0 ; i<q ; i++) cin >> que[i];

    vector<int> a(n);
    vector<int> ans(n);

    f(0,que,a,0,ans);
    int inv=binexp(binexp(2,q),MOD-2);
    // vdebug(a)
    for(auto x : ans){
        int tmp=(x*inv)%MOD;
        cout<< tmp <<"\n";
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