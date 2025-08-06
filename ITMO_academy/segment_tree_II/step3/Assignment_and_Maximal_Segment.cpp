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
    int pref,suf,sum,seg,lazy;
    Node(int x=0){pref=suf=sum=seg=x;lazy=LLONG_MAX;}
};

vector<Node> st;

void push(int node, int l, int r){
    if(st[node].lazy == LLONG_MAX) return;
    int tmp=(r-l+1)*st[node].lazy;
    // st[node].sum=tmp;
    // st[node].pref=st[node].suf=st[node].seg=max(0LL,st[node].sum);
    st[node].sum=st[node].pref=st[node].suf=st[node].seg=tmp;
    if(l != r){
        st[node*2].lazy=st[node].lazy;
        st[node*2+1].lazy=st[node].lazy;
    }
    st[node].lazy=LLONG_MAX;
}

Node merge(Node &left, Node &right){
    Node ans;
    ans.sum=left.sum+right.sum;
    ans.suf=max(right.suf, right.sum+left.suf);
    ans.pref=max(left.pref, left.sum+right.pref);
    ans.seg=max({left.seg, right.seg, left.suf+right.pref});
    return ans;
}

void assign_range(int node, int l, int r, int query_l, int query_r, int val){
    push(node, l, r);
    if(query_l<=l && r<=query_r){
        st[node].lazy=val;
        push(node, l, r);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    assign_range(node*2, l, mid, query_l, query_r, val);
    assign_range(node*2+1, mid+1, r, query_l, query_r, val);
    st[node]=merge(st[node*2],st[node*2+1]);
}

void solve(){
    int n,m; cin >> n >> m;

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);

    for(int i=0 ; i<m ; i++){
        int l,r,val; cin >> l >> r >> val;
        assign_range(1,0,n-1,l,r-1,val);
        cout<< max(0LL, st[1].seg) <<"\n";
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