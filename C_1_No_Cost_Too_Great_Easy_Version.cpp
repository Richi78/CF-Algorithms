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
    vector<int> a(n),b(n);
    map<int,int> mp;
    int cnt_e=0 , cnt_o=0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(a[i]&1) cnt_o++;
        else cnt_e++;
    }
    for(int i=0 ; i<n ; i++) cin >> b[i];    

    int ans=1e9;
    if(cnt_e == 0) ans=min(ans,2LL);
    else if(cnt_e == 1) ans=min(ans,1LL);
    else if(cnt_e >= 2){
        cout<< "0\n"; return;
    }
    for(int i=0 ; i<n ; i++){
        // it won't work this way
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}