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

    vector<int> pref1(n+1) , pref2(n+1);
    for(int i=0 ; i<n ; i++){
        pref1[i+1]=pref1[i]+a[i];
    }
    sort(all(a));
    for(int i=0 ; i<n ; i++){
        pref2[i+1]=pref2[i]+a[i];
    }

    int q; cin >> q;
    for(int rep=0 ; rep<q ; rep++){
        int t,l,r; cin >> t >> l >> r;
        if(t == 1){
            cout<< (pref1[r]-pref1[l-1]) <<"\n";
        }else{
            cout<< (pref2[r]-pref2[l-1]) <<"\n";
        }
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}