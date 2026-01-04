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

bool check(int ini, vector<int> &a){
    int n=a.size();
    vector<int> tmp(n+1);
    tmp[1]=ini; // 0->L     1->R
    for(int i=1 ; i<n ; i++){
        if(abs(a[i]-a[i-1]) > 2) return false;
        else if(a[i]-a[i-1] == 1) tmp[i+1]=0;
        else if(a[i]-a[i-1] == -1) tmp[i+1]=1;
        else tmp[i+1]=tmp[i]^1;
    }
    vector<int> pref(n+1) , suf(n+1);
    for(int i=1 ; i<=n ; i++){
        if(tmp[i]==0) pref[i]=pref[i-1]+1;
        else pref[i]=pref[i-1];
    }
    suf[n]= tmp[n]==1?1:0;
    for(int i=n-1 ; i>=1 ; i--){
        if(tmp[i]==1) suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1];
    }
    for(int i=1 ; i<=n ; i++){
        int cur=1+pref[i-1]+ (i+1<=n? suf[i+1] : 0);
        if(a[i-1] == cur)continue;
        else return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int ans=0;
    if(check(0, a)) ans++;
    if(check(1, a)) ans++;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}