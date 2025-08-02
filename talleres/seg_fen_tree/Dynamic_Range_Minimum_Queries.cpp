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
    if(r<query_l || query_r<l) return 1e17;
    int mid=l+(r-l)/2;
    return min(query(node*2, l, mid, query_l,query_r),
            query(node*2+1, mid+1, r, query_l, query_r));
}

void update_recursive(int node, int l, int r, int query_l, int query_r, int val){
    if(query_l<=l && r<=query_r){
        st[node]=val;
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    update_recursive(node*2, l, mid, query_l, query_r, val);
    update_recursive(node*2+1, mid+1, r, query_l, query_r, val);
    st[node]=min(st[node*2],st[node*2+1]);
}

void update_iterative(int idx, int val, int n){
    st[n+idx]=val;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=min(st[i*2],st[i*2+1]);
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    while(__builtin_popcountll(n) != 1){
        a.push_back(0) , n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++){
        st[n+i]=a[i];
    }
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=min(st[2*i],st[2*i+1]);
    }

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // update
            int pos, val; cin >> pos >> val;
            update_recursive(1,0,n-1,pos-1,pos-1,val);
            // update_iterative(pos-1,val,n);
        }else{
            // query
            int a,b; cin >> a >> b;
            cout<< query(1,0,n-1,a-1,b-1) <<"\n";
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}