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
    int n,m; cin >> n >> m;
    vector<int> a(m);
    for(int i=0 ; i<m ; i++) cin >> a[i];
    sort(all(a));
    vector<pair<int,int>> ans;
    for(int i=0 ; i<m ; i++){
        ans.emplace_back(a[i],a[m-1-i]);
    }
    sort(all(ans),[&](auto x, auto y){
        return abs(x.first/100-x.second/100) > abs(y.first/100-y.second/100);
    });
    for(int i=0 ; i<n ; i++){
        for(int rep=0 ; rep<3 ; rep++){
            cout<< ans[i].first <<" "<< ans[i].second <<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}