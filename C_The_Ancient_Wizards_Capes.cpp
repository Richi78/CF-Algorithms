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
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // falta corregir, ta mal
    if(n==2){
        if(a[0]==a[1]) cout<<"2\n";
        else cout<<"1\n";
        return;
    }
    for(int i=1 ; i+1<n ; i++){
        if(a[i-1]<a[i] && a[i]>a[i+1]){
            cout<<"0\n"; return;
        }
        if(a[i-1]>a[i] && a[i]<a[i+1]){
            cout<<"0\n"; return;
        }
    }

    bool ac=true;
    bool dec=true;
    bool eq=true;
    for(int i=1 ; i<n ; i++){
        ac&=(a[i-1]<a[i]);
        dec&=(a[i-1]>a[i]);
        eq&=(a[i-1]==a[i]);
    }
    if(eq){
        cout<<"2\n"; return;
    }
    if(dec || ac){
        cout<<"1\n"; return;
    }

    int from=0;
    for(int i=1 ; i<n ; i++){
        if(a[i] == a[i-1]) from=i;
        else break;
    }

    bool ac2=true;
    bool dec2=true;
    for(int i=from+1 ; i<n ; i++){
        // ac2&=(a[i-1]<a[i]);
        dec2&=(a[i-1]>a[i]);
    }
    // debug2(ac2,dec2)
    if(dec2){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}