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
    multiset<int> st;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        st.insert(x);
    }
    for(int rep=0 ; rep<m ; rep++){
        int x; cin >> x;
        auto it=st.lower_bound(x);
        if(*it == x){
            cout<< x <<"\n";
            st.erase(it);
        }else if(it != st.begin()){
            cout<< *(--it) <<"\n";
            st.erase(it);
        }else{
            cout<< "-1\n";
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