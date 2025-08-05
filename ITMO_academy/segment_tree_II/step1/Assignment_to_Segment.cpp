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

struct Node{
    int val,lazy;
    Node(int x=0){val=x;lazy=LLONG_MAX;}
};

vector<Node> st;

void push(int node, int l, int r){
    if(st[node].lazy == LLONG_MAX) return;
    st[node].val=st[node].lazy;
    if(l != r){
        st[node*2].lazy=st[node].lazy;
        st[node*2+1].lazy=st[node].lazy;
    }
    st[node].lazy=LLONG_MAX;
}

Node query(int node, int l, int r, int query_l, int query_r){
    push(node, l, r);
    if(l == r) return st[node];
    if(r<query_l || query_r<l) return Node(-1);
    int mid=l+(r-l)/2;
    if(query_r <= mid)
        return query(node*2, l, mid, query_l, query_r);
    return query(node*2+1, mid+1, r, query_l, query_r);
}

void set_range(int node, int l, int r, int query_l, int query_r, int val){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        st[node].lazy=val;
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    set_range(node*2, l, mid, query_l, query_r, val);
    set_range(node*2+1, mid+1, r, query_l, query_r, val);
}

void solve(){
    int n,m; cin >> n >> m;

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);
    
    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            int l,r,val; cin >> l >> r >> val;
            set_range(1,0,n-1,l,r-1,val);
        }else{
            int idx; cin >> idx;
            Node ans=query(1,0,n-1,idx,idx);
            cout<< ans.val <<"\n";
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