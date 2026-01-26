#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];    
    for(int i=0 ; i<n ; i++) cin >> b[i];    
    for(int i=n-1 ; i>=0 ; i--){
        a[i]=max(a[i],b[i]);
        if(i+1<n) a[i]=max(a[i],a[i+1]);
    }
    vector<int> pref(n+1);
    for(int i=1 ; i<=n ; i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    for(int rep=0 ; rep<q ; rep++){
        int l,r; cin >> l >> r;
        cout<< pref[r] - pref[l-1] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}