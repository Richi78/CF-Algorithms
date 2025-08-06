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

const int MOD=1e9+7;

struct Node{
    int val,lazy;
    Node(int x=1){val=x;lazy=1;}
};

vector<Node> st;

void push(int node, int l, int r){
    if(st[node].lazy == 1) return;
    st[node].val=(st[node].val*st[node].lazy)%MOD;
    if(l != r){
        st[node*2].lazy=(st[node*2].lazy*st[node].lazy)%MOD;
        st[node*2+1].lazy=(st[node*2+1].lazy*st[node].lazy)%MOD;
    }
    st[node].lazy=1;
}

int query(int node, int l, int r, int query_l, int query_r){
    push(node, l, r);
    if(query_l<=l && r<=query_r) return st[node].val;
    if(r<query_l || query_r<l) return 0;
    int mid=l+(r-l)/2;
    return (query(node*2, l, mid, query_l, query_r)
        + query(node*2+1, mid+1, r, query_l, query_r))%MOD;
}

void mult_range(int node, int l, int r, int query_l, int query_r, int val){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        st[node].lazy=val;
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    mult_range(node*2, l, mid, query_l, query_r, val);
    mult_range(node*2+1, mid+1, r, query_l, query_r, val);
    st[node].val=(st[node*2].val+st[node*2+1].val)%MOD;
}

void solve(){
    int n,m; cin >> n >> m;

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);
    for(int i=n-1 ; i>=1 ; i--) 
        st[i].val=(st[2*i].val+st[2*i+1].val)%MOD;

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // mult in range
            int l,r,val; cin >> l >> r >> val;
            mult_range(1,0,n-1,l,r-1,val);
        }else{
            // sum query
            int l,r; cin >> l >> r;
            cout<< query(1,0,n-1,l,r-1) <<"\n";
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