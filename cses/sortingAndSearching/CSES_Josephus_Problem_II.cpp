#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//find_by_order, order_of_key ; greater<int>, less_equal<int>
// // insert -> logn | delete -> | find kth element -> logn | find # of elements smaller than x -> logn 
// // up and lb work opposite
// // to erase in a multiset s.erase(s.upperbound(x))

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,k; cin >> n >> k;
    pbds st;
    for(int i=1 ; i<=n ; i++) st.insert(i);

    int cur=0;
    while(st.size()){
        int tmp= (cur + k)%st.size();
        cur=tmp;
        auto it=st.find_by_order(tmp);
        cout<< *it <<" ";
        st.erase(it);
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}