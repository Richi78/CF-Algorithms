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
    vector<array<int,3>> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.push_back( {u,v,i} );
    }    
    sort(all(a), [&](auto x, auto y){
        if(x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    });
    map<int,int> mp;
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        if(mp.find(a[i][0]) != mp.end()) continue;
        ans.push_back(a[i][2]+1);
        mp[a[i][0]]++;
    }
    cout<< ans.size() <<"\n";
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