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

const int INF=1e18;

void solve(){
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> dp(x+1, INF);
    dp[0]=0;
    
    // pull dp
    // for(int i=1 ; i<=x ; i++){
    //     for(int j=0 ; j<n ; j++){
    //         if(i-a[j]>=0){
    //             dp[i]=min(dp[i],dp[i-a[j]]+1);
    //         }
    //     }
    // }

    // push dp
    for(int s=0 ; s<x ; s++){
        // we know value of dp[s] and we propagate further
        for(int i=0 ; i<n ; i++){
            if(s+a[i] <= x){
                dp[s+a[i]]=min(dp[s+a[i]],dp[s]+1);
            }
        }
    }
    cout<< (dp[x]==INF?-1:dp[x]) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}