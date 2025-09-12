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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        if(i&1) sum-=a[i];
        else sum+=a[i];
    }

    if(n == 1){
        cout<< sum <<"\n"; return;
    }

    int ans=sum;
    {
        // pos - pos , neg - neg
        if(n&1) uax(ans, sum+n-1);
        else uax(ans, sum+n-2);
    }

    int add=0;
    {
        // neg - pos
        int mx=-1e18;
        for(int i=1 ; i<n ; i+=2){
            mx=max(mx,2LL*a[i]-i);
        }
        int mn=1e18;
        for(int i=0 ; i<n ; i+=2){
            mn=min(mn,2LL*a[i]-i);
        }
        add=max(add, mx-mn);
    }
    {
        // pos - neg
        int mx=-1e18;
        for(int i=1 ; i<n ; i+=2){
            mx=max(mx,2LL*a[i]+i);
        }
        int mn=1e18;
        for(int i=0 ; i<n ; i+=2){
            mn=min(mn,2LL*a[i]+i);
        }
        add=max(add, mx-mn);
    }

    uax(ans, sum+add);

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}