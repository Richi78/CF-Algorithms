#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
// find_by_order (kth element index 0)
// order_of_key (# items less than ) 

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

struct Event{
    int ini;
    int fin;
    int id;
};

void solve(){
    int n; cin >> n;
    vector<Event> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.push_back(Event{u,v,i});
    }
    sort(all(a), [&](Event x, Event y){
        if(x.ini == y.ini) return x.fin > y.fin;
        return x.ini < y.ini;
    });
    vector<int> contains(n);
    vector<int> contained(n);
    {
        ordered_set st;
        st.insert(make_pair(a[0].fin,a[0].id));
        for(int i=1 ; i<n ; i++){
            int less_than=st.order_of_key({a[i].fin,-1e18});
            contained[a[i].id]=st.size()-less_than;
            st.insert(make_pair(a[i].fin,a[i].id));
        }
    }
    {
        ordered_set st;
        st.insert(make_pair(a[n-1].fin,a[n-1].id));
        for(int i=n-2 ; i>=0 ; i--){
            int less_than=st.order_of_key({a[i].fin+1,-1e18});
            contains[a[i].id]=less_than;
            st.insert(make_pair(a[i].fin,a[i].id));
        }
    }

    for(auto x : contains) cout<< x <<" ";
    cout<<"\n";
    for(auto x : contained) cout<< x <<" ";
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