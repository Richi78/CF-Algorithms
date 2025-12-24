#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> pref(n);
    for(int i=1 ; i<n ; i++){
        pref[i]=pref[i-1]+abs(a[i]-a[i-1]);  
    }

    int ans=1e18;
    for(int i=0 ; i<n ; i++){
        if(i==0){
            ans=min(ans,pref[n-1]-pref[1]);
        }else if(i==n-1){
            ans=min(ans,pref[n-2]);
        }else{
            int right=0;
            if(i+1<n){
                right=pref[n-1]-pref[i+1];
            }
            int left=0;
            if(i-1>=0){
                left=pref[i-1];
            }
            ans=min(ans,right+left+abs(a[i-1]-a[i+1]));
        }
    }
    cout<< ans <<"\n";

    // int idx=-1;
    // int val=0;
    // int mx=0;
    // for(int i=0 ; i+1<n ; i++){
    //     int tmp=abs(a[i]-a[i+1]);
    //     if(tmp >= val){
    //         val=tmp;
    //         mx=max({a[i],a[i+1],mx});
    //         if(a[i] == mx) idx=i;
    //         else if(a[i+1] == mx) idx=i+1;
    //     }
    // }
    // vector<int> x;
    // for(int i=0 ; i<n ; i++){
    //     if(i != idx) x.push_back(a[i]);
    // }
    // int ans=0;
    // for(int i=0 ; i+1<x.size() ; i++){
    //     ans+=abs(x[i]-x[i+1]);
    // }
    // cout<< ans <<"\n";
    // vdebug(x)
    // debug1(idx)
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}