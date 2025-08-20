#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,h; cin >> n >> h;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    int l=0 , r=n-1;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        vector<int> tmp(a.begin(), a.begin()+mid+1);
        sort(all(tmp), greater<int>());
        int sz=tmp.size();
        int x=0;
        for(int i=0 ; i<sz ; i+=2){
            x+=tmp[i];
        }
        if(x <= h){
            ans=mid+1;
            l=mid+1;
        }else{
            r=mid-1;
        }
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

