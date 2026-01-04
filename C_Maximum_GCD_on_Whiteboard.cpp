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
    vector<int> freq(n+1);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x; freq[x]++;
    } 
    for(int i=1 ; i<=n ; i++) freq[i]+=freq[i-1];
    for(int i=n ; i>=1 ; i--){
        int total=freq[i]-freq[i-1];
        if(4*i <= n) total+=freq[n]-freq[4*i-1];
        if(3*i <= n) total+=freq[3*i]-freq[3*i-1];
        if(2*i <= n) total+=freq[2*i]-freq[2*i-1];
        if(n-total <= k){
            cout<< i <<"\n"; return;
        }
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}