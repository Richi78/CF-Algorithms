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
    vector<int> a(2*n);
    for(int i=0 ; i<2*n ; i++) cin >> a[i];
    
    vector<int> ans(n);
    int tmp=0;
    for(int i=0 ; i<2*n ; i++){
        if(i<n) a[i]*=-1;
        tmp+=a[i];
    }
    ans[n-1]=tmp;
    int l=n-1 , r=n , aux=0;
    n--;
    while(n>0){
        ans[n-1]=tmp-2*aux-2*(a[l]+a[r]);
        tmp=ans[n-1];
        aux*=-1;
        aux+=-(a[l]+a[r]);
        l--; r++;
        n--;
    }
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}