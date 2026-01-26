#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,m; cin >> n >> m;
    multiset<int> st , st2;
    for(int i=0 ; i<m ; i++){
        int x; cin >> x; st.insert(x); st2.insert(x);
    }
    int mx=0;
    for(int i=0 ; i<n ; i++){
        auto it=prev(st.end());
        int val=*it;
        mx+=val;
        st.erase(it);
        if(val>1) st.insert(val-1);
    }
    int mn=0;
    for(int i=0 ; i<n ; i++){
        auto it=st2.begin();
        int val=*it;
        mn+=val;
        st2.erase(it);
        if(val>1) st2.insert(val-1);
    }
    cout<< mx <<" "<< mn <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)
    solve();
}