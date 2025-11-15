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
    vector<int> a(n+1);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i+1];
        sum+=a[i+1];
    }
    vector<int> pref(n+1);
    for(int i=0 ; i<n ; i++){
        pref[i+1]=pref[i]+a[i+1];
    }

    int ans=0;
    int mn=0; 
    for(int i=1 ; i<=n ; i++){
        int tmp=i*i+i-pref[i]; 
        mn=min(mn,i*i-i-pref[i-1]); 
        ans=max(ans,tmp-mn);
    }
    cout<< sum+ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}