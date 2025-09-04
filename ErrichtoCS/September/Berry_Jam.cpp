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
    vector<int> a(2*n);
    for(int i=0 ; i<2*n ; i++) cin >> a[i];

    map<int,int> mp;
    int ans=1e18;
    int cnt_1=0 , cnt_2=0;
    for(int i=2*n-1 ; i>=n ; i--){
        if(a[i] == 1) cnt_1++;
        else cnt_2++;
        int delta=cnt_1-cnt_2;
        mp[delta]=i;
        if(delta == 0){
            ans=min(ans, i);
        } 
    }

    cnt_1 = cnt_2 = 0;
    vector<int> d(n);
    for(int i=0 ; i<n ; i++){
        if(a[i] == 1) cnt_1++;
        else cnt_2++;
        int delta=cnt_1-cnt_2;
        d[i]=delta;
        if(delta == 0){
            ans=min(ans, 2*n-(i+1));
        }
    }
    for(int i=n-1 ; i>=0 ; i--){
        if(mp[-d[i]] != 0){
            ans=min(ans, mp[-d[i]] - (i+1));
        }
    }
    cout<< (ans==1e18?2*n:ans) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}