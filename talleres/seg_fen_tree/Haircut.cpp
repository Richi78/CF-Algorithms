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

vector<int> st;

int query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node];
    if(r<query_l || query_r<l) return 0;
    int mid=l+(r-l)/2;
    return query(node*2, l, mid, query_l, query_r)
        + query(node*2+1, mid+1, r, query_l, query_r);
}

void update(int idx, int n){
    st[n+idx]++;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=st[i*2]+st[i*2+1];
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]=x+1;
    } 
    
    int mx=*max_element(all(a));
    int tmp_mx=mx;

    while(__builtin_popcountll(mx) != 1){
         mx++;
    }

    st.resize(2*mx);
    
    vector<int> inv(tmp_mx+1);
    for(int i=0 ; i<n ; i++){
        inv[a[i]]+=query(1,0,mx-1,a[i],mx-1);
        update(a[i]-1,mx);
    }

    vector<int> ans(tmp_mx+1);
    for(int i=1 ; i<=n ; i++){
        ans[i]=ans[i-1]+inv[i-1];
    }
    for(int i=1 ; i<=n ; i++){
        cout<< ans[i] <<"\n";
    }
}

signed main(){
    FIO;
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}
