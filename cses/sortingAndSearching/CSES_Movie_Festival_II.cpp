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
    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.emplace_back(u,v);
    }
    sort(all(a), [&](auto x, auto y){
        if(x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    int ans=0;
    multiset<int> available , st;
    for(int i=0 ; i<k ; i++) available.insert(0);
    for(int i=0 ; i<n ; i++){
        while(!st.empty() && a[i].first >= *st.begin()){
            available.insert(*st.begin());
            st.erase(st.begin());
        }
        auto it=available.lower_bound(a[i].first);
        if(it!=available.end() && *it == a[i].first){
            available.erase(it);
            ans++;
            st.insert(a[i].second);
        }else if(it!=available.begin() && it != available.begin()){
            it--;
            available.erase(it);
            ans++;
            st.insert(a[i].second);
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
