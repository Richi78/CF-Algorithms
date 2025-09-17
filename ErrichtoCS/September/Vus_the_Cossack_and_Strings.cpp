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
    string a,b; cin >> a >> b;
    int sz_b=b.size();
    int sz_a=a.size();
    vector<int> pref(sz_a+1);
    for(int i=0 ; i<sz_a ; i++){
        pref[i+1] = pref[i] + (a[i]=='1');
    }
    int cnt=0;
    for(int i=0 ; i<sz_b ; i++){
        if(b[i]=='1') cnt++;
    }
    int ans=0;
    for(int i=sz_b-1 ; i<sz_a; i++){
        if( (pref[i+1]-pref[i-(sz_b-1)])%2 == cnt%2 )
            ans++;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}