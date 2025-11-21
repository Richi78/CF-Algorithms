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
    vector<int> a(n) , pref(n+1);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        if(i){
            pref[i+1]=min(pref[i],a[i]); 
        }else pref[i+1]=a[i];
    } 

    vector<int> suf(n);
    suf[n-1]=a[n-1];
    for(int i=n-2 ; i>=0 ; i--) suf[i]=max(a[i],suf[i+1]);

    bool ok=true;
    for(int i=0 ; i<n && ok ; i++){
        if(pref[i] > suf[i]) ok=false;
    }
    cout<< (ok?"YES":"NO") <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}