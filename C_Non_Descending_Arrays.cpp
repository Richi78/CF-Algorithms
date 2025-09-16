#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int n;

int f(int idx, vector<int> &a, vector<int> &b, vector<int> &dp){
    if(idx == -1) return 0;

    if(dp[idx] != -1) return dp[idx];

    int x=0;
    if(is_sorted(all(a)) && is_sorted(all(b))){
        x=1;
    }

    int notake=x+f(idx-1, a, b, dp);
    int tmp=a[idx];
    a[idx]=b[idx]; b[idx]=tmp;
    x=0;
    if(is_sorted(all(a)) && is_sorted(all(b))){
        x=1;
    }
    int take=x+f(idx-1, a, b, dp);
    b[idx]=a[idx]; a[idx]=tmp; 

    return dp[idx]=(take+notake)%MOD;
}

void solve(){
    cin >> n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];    
    for(int i=0 ; i<n ; i++) cin >> b[i];    

    
    vector<int> dp(n+1,-1);
    int ans = f(n-1, a, b, dp);
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}