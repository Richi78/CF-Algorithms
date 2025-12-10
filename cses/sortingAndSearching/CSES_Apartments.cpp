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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n) , b(m);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<m ; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int i=0; // ptr applicants
    int j=0; // ptr apartments
    int ans=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j]) <= k){
            ans++;
            i++; j++;
        }else if(b[j] > a[i]) i++;
        else if(a[i] > b[j]) j++;
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