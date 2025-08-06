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
    Node(int x=0){val=x;lazy=0;}
};

vector<Node> st;

void push(int node, int l, int r){
    if(st[node].lazy == 0) return;
    st[node].val=(r-l+1)-st[node].val;
    if(l != r){
        st[node*2].lazy^=st[node].lazy;
        st[node*2+1].lazy^=st[node].lazy;
    }
    st[node].lazy=0;
}

int query(int node, int l, int r, int k){
    push(node, l, r);
    if(st[node].val <= k) return -1;
    if(l == r) return l;
    int mid=l+(r-l)/2;
    int left=query(node*2, l, mid, k);
    if(left == -1)
        return query(node*2+1, mid+1, r, k-st[node*2].val);
    return left;
}

void flip_range(int node, int l, int r, int query_l, int query_r){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        st[node].lazy=1;
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    flip_range(node*2, l, mid, query_l, query_r);
    flip_range(node*2+1, mid+1, r, query_l, query_r);
    st[node].val=st[node*2].val+st[node*2+1].val;
}

void solve(){
    int n,m; cin >> n >> m;

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // flip range
            int l,r; cin >> l >> r;
            flip_range(1,0,n-1,l,r-1);
        }else{
            // kth one
            int k; cin >> k;
            cout<< query(1,0,n-1,k) <<"\n";
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