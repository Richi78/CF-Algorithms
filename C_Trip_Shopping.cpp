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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    vector<pair<int,int>> c;
    int sum=0;
    for(int i=0 ; i<n ; i++){
        c.emplace_back(min(a[i],b[i]) , max(a[i],b[i]));
        sum+=abs(a[i]-b[i]);
    }
    sort(all(c));
    for(int i=1 ; i<n ; i++){
        if(c[i-1].second >= c[i].first){
            cout<< sum <<"\n"; return;
        }
    }
    int mn=1e18;
    for(int i=1 ; i<n ; i++){
        mn=min(mn,c[i].first-c[i-1].second);
    }
    cout<< sum+2*mn <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}