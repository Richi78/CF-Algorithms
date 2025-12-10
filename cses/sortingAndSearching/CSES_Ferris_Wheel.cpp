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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));
    int ans=0;
    int i=0 , j=n-1;
    while(i<=j){
        if(i==j){
            i++;
        }else if(a[i]+a[j] > k){
            j--;
        }else if(a[i]+a[j] <= k){
            i++; j--;
        }
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