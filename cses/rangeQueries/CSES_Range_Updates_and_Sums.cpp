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
    int val,lazy_add,lazy_set;
    Node(int x=0){
        val=x; // sum
        lazy_add=lazy_set=0;
    }
};

vector<Node> st;

Node merge(Node &left, Node & right){
    Node ans;
    ans.val=left.val+right.val;
    return ans;
}

void push(int node, int l, int r){
    if(st[node].lazy_set != 0){
        st[node].val=st[node].lazy_set*(r-l+1);
        if(l != r){
            st[node*2].lazy_set=st[node].lazy_set;
            st[node*2].lazy_add=0;
            st[node*2+1].lazy_set=st[node].lazy_set;
            st[node*2+1].lazy_add=0;
        }
        st[node].lazy_set=0;
    }
    if(st[node].lazy_add != 0){
        st[node].val+=st[node].lazy_add*(r-l+1);
        if(l != r){
            st[node*2].lazy_add+=st[node].lazy_add;
            st[node*2+1].lazy_add+=st[node].lazy_add;
        }
        st[node].lazy_add=0;
    }
}

int query(int node, int l, int r, int query_l, int query_r){
    push(node, l , r);
    if(query_l<=l && r<=query_r) return st[node].val;
    if(r<query_l || query_r<l) return 0;
    int mid=l+(r-l)/2;
    int left=query(node*2, l, mid, query_l, query_r);
    int right=query(node*2+1, mid+1, r, query_l, query_r);
    return left+right;
}

void update(int node, int l, int r, int query_l, int query_r, int val, int type){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        if(type == 1){
            // add range
            st[node].lazy_add+=val;
        }else{
            // set range
            st[node].lazy_set=val;
        }
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    update(node*2, l, mid, query_l, query_r, val, type);
    update(node*2+1, mid+1, r, query_l, query_r, val, type);
    st[node].val=st[node*2].val + st[node*2+1].val;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    while(__builtin_popcount(n) != 1){
        a.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++){
        st[n+i]=Node(a[i]);
    }
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1 || type == 2){
            // 1 add range      2 set range
            int l,r,val; cin >> l >> r >> val;
            update(1,0,n-1,l-1,r-1,val,type);
        }else{
            // sum query
            int l,r; cin >> l >> r;
            cout<< query(1,0,n-1,l-1,r-1) <<"\n";
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

