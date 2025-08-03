#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    multiset<int> st;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        st.insert(x);
    }

    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        int target=n-a[i];
        
        auto it=st.lower_bound(target);
        if(it == st.end()) it=st.begin();
        ans.push_back((a[i]+*it)%n);
        st.erase(it);
    }

    for(int i=0 ; i<n ; i++){
        cout<< ans[i] <<" ";
    }
    cout<< "\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}