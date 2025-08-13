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
    int mx1,cnt1,mx2,cnt2;
    Node(int x=0){
        mx1=cnt1=mx2=cnt2=x;
    }
};

vector<Node> st;

Node merge(Node left, Node right){
    Node ans; 
    if(left.mx1 == right.mx1){
        ans.mx1=left.mx1;
        ans.cnt1=left.cnt1+right.cnt1;
        if(left.mx2 == right.mx2){
            ans.mx2=left.mx2;
            ans.cnt2=left.cnt2+right.cnt2;
        }else if(left.mx2>right.mx2){
            ans.mx2=left.mx2;
            ans.cnt2=left.cnt2; 
        }else{
            ans.mx2=right.mx2;
            ans.cnt2=right.cnt2;
        }
    }else if(left.mx1>right.mx1){
        ans.mx1=left.mx1;
        ans.cnt1=left.cnt1;
        if(left.mx2 == right.mx1){
            ans.mx2=left.mx2;
            ans.cnt2=left.cnt2+right.cnt1;
        }else if(left.mx2 > right.mx1){
            ans.mx2=left.mx2;
            ans.cnt2=left.cnt2;
        }else{ // right.mx1 > left.mx2
            ans.mx2=right.mx1;
            ans.cnt2=right.cnt1;
        }
    }else if(right.mx1 > left.mx1){ // right.mx1 > left.mx1
        ans.mx1=right.mx1;
        ans.cnt1=right.cnt1;
        if(right.mx2 == left.mx1){
            ans.mx2=right.mx2;
            ans.cnt2=right.cnt2+left.cnt1;
        }else if(right.mx2 > left.mx1){
            ans.mx2=right.mx2;
            ans.cnt2=right.cnt2;
        }else{ // right.mx2 < left.mx1
            ans.mx2=left.mx1;
            ans.cnt2=left.cnt1;
        }
    }
    return ans;
}

Node query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node];
    if(r<query_l || query_r<l) return Node(0);
    int mid=l+(r-l)/2;
    Node left=query(node*2, l, mid, query_l, query_r);
    Node right=query(node*2+1, mid+1, r, query_l, query_r);
    return merge(left, right);
}

void update(int idx, int val, int n){
    st[n+idx].mx1=val;
    for(int i=(n+idx)/2 ; i>=1 ; i/=2){
        st[i]=merge(st[2*i],st[2*i+1]);
    }
}

void solve(){
    int n,m; cin >> n >> m;
    int tmp_n=n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);
    for(int i=0 ; i<tmp_n ; i++){
        st[n+i].mx1=a[i];
        st[n+i].cnt1=1;
    }
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }
    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // update
            int pos,val; cin >> pos >> val;
            update(pos-1,val,n);
        }else{
            // query
            int l,r; cin >> l >> r;
            cout<< query(1,0,n-1,l-1,r-1).cnt2 <<"\n";
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

