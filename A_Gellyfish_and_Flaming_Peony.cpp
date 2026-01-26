#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
// #define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int gcd(int a, int b){return b==0?a:gcd(b,a%b);}
const int INF=1e9;

void solve(){
    int n; cin >> n;    
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int mx=*max_element(all(a));
    vector<int> dp(mx+1,INF);
    for(auto x : a){
        dp[x]=0;
        for(int i=1 ; i<=mx ; i++){
            int tmp=gcd(i,x);
            dp[tmp]=min(dp[tmp],dp[i]+1);
        }
    }
    for(int i=1 ; i<=mx ; i++){
        if(dp[i] != INF){
            int already=0;
            for(auto x : a){
                if(x==i) already++;
            }
            cout<< dp[i]+min(n-1,n-already) <<"\n"; 
            break;
        }
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}