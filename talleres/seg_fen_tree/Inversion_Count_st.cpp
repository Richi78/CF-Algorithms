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
// int st[1<<25];

int query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r){
        return st[node];
    }
    if(query_r<l || r<query_l){
        return 0;
    }
    int mid=l+(r-l)/2;
    return query(node*2, l, mid, query_l, query_r)
        + query(node*2+1, mid+1, r, query_l, query_r);
}

void update(int idx, int n){
    st[n+idx]++;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=st[2*i]+st[2*i+1];
    }
}

void solve(){
    st.clear();
    // memset(st, 0 , sizeof(st));
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int mx=*max_element(all(a));

    while(__builtin_popcount(mx) != 1){
        mx++;
    }

    st.resize(2*mx);

    int cnt=0;
    for(int i=0 ; i<n ; i++){
        cnt+=query(1, 0, mx-1, a[i] , mx-1);
        update(a[i]-1, mx);
    }
    cout<< cnt <<"\n";

}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}