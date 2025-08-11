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

const int MOD=998244353;

struct Node{
    int sum,A,B,AB,lazy_a,lazy_b;
    Node(int x=0){
        sum=0;
        A=B=AB=x;
        lazy_a=lazy_b=0;
    }
};

vector<Node> st;

Node merge(Node &left, Node &right){
    Node ans;
    ans.sum=(left.AB + right.AB)%MOD;
    ans.A=(left.A+right.A)%MOD;
    ans.B=(left.B+right.B)%MOD;
    ans.AB=(left.AB+right.AB)%MOD;
    return ans;
}

void push(int node, int l, int r){
    if(st[node].lazy_a != 0){
        st[node].AB=(st[node].AB+(st[node].lazy_a*st[node].B)%MOD)%MOD;
        st[node].A= (st[node].A + (st[node].lazy_a*(r-l+1))%MOD)%MOD;
        if(l != r){
            st[node*2].lazy_a=(st[node*2].lazy_a + st[node].lazy_a)%MOD;
            st[node*2+1].lazy_a=(st[node*2+1].lazy_a + st[node].lazy_a)%MOD;
        }
        st[node].lazy_a=0;
    }
    if(st[node].lazy_b != 0){
        st[node].AB=(st[node].AB+(st[node].lazy_b*st[node].A)%MOD)%MOD;
        st[node].B=(st[node].B +(st[node].lazy_b*(r-l+1))%MOD)%MOD;
        if(l != r){
            st[node*2].lazy_b=(st[node*2].lazy_b + st[node].lazy_b)%MOD;
            st[node*2+1].lazy_b=(st[node*2+1].lazy_b + st[node].lazy_b)%MOD;
        }
        st[node].lazy_b=0;
    }
}

int query(int node, int l, int r, int query_l, int query_r){
    push(node, l, r);
    if(query_l<=l && r<=query_r) return st[node].AB;
    if(r<query_l || query_r<l) return 0;
    int mid=l+(r-l)/2;
    int left=query(node*2, l, mid, query_l, query_r);
    int right=query(node*2+1, mid+1, r, query_l, query_r);
    return (left+right)%MOD;
}

void add_range(int node, int l, int r, int query_l, int query_r, int val, int type){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        if(type == 1){
            // A
            st[node].lazy_a=val;
        }else{
            // B
            st[node].lazy_b=val;
        }
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    add_range(node*2,l,mid,query_l,query_r,val,type);
    add_range(node*2+1,mid+1,r,query_l,query_r,val,type);
    st[node]=merge(st[node*2],st[node*2+1]);
}

void solve(){
    int n,m; cin >> n >> m;
    int tmp_n=n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    
    while(__builtin_popcountll(n) != 1) n++;

    st.resize(2*n);

    for(int i=0 ; i<tmp_n ; i++){
        st[n+i].A=a[i];
        st[n+i].B=b[i];
        st[n+i].AB=(st[n+i].A*st[n+i].B)%MOD;
        st[n+i].sum=st[n+i].AB;
    }
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // add range A
            int l,r,x; cin >> l >> r >> x;
            add_range(1,0,n-1,l-1,r-1,x,1);
        }else if(type == 2){
            // add range B
            int l,r,x; cin >> l >> r >> x;
            add_range(1,0,n-1,l-1,r-1,x,2);
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