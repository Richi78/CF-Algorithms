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
    int n,a,b; cin >> n >> a >> b;
    vector<int> x(n) , pref(n+1);
    for(int i=0 ; i<n ; i++) cin >> x[i] , pref[i+1]=pref[i]+x[i];
    int mx=-1e18;
    multiset<int> st;
    for(int i=a ; i<=b ; i++){
        st.insert(pref[i]);
    }
    int i=a , j=b;
    while(i <= j){
        mx=max(mx,*st.rbegin()-pref[i-a]);
        if(j+1<=n){
            j++;
            st.insert(pref[j]);
        }
        st.erase(st.find(pref[i]));
        i++;
    }
    cout<< mx <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}