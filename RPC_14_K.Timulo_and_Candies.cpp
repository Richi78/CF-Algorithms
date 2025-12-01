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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];

    if(n == 1){
        cout<< a[0] <<"\n"; return;
    }

    int ans=0;
    int mx=a[0] , last=b[0];
    for(int i=1 ; i<n ; i++){
        if(i == n-1){
            if(b[i] != last){
                ans+=mx;
                ans+=a[i];
            }else{
                mx=max(mx,a[i]);
                ans+=mx;
            }
        }else{
            if(b[i] != last){
                ans+=mx;
                mx=a[i];
                last=b[i];
            }else{
                mx=max(mx,a[i]);
            }
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