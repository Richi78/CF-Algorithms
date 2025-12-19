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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    if(n==1){
        cout<< "1\n"; return;
    }

    int ans=1;
    int sz=1;
    int i=0 , j=1;
    multiset<int> st;
    st.insert(a[i]);
    while(i<n && j<n){
        if(st.count(a[j]) == 0){
            st.insert(a[j]);
            sz++;
            j++;
            ans=max(ans,sz);
        }else{
            while(a[i] != a[j]){
                st.erase( st.find(a[i]) );
                i++; sz--;
            }
            st.erase( st.find(a[i]) );
            i++; sz--;
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