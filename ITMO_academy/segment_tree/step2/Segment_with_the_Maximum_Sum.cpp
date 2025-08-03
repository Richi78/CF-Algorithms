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
    int sum,pref,suf,seg;
    Node(int x=0){sum=pref=suf=seg=x;}
};

vector<Node> st;

Node merge(Node &left, Node &right){
    Node ans;
    ans.sum=left.sum+right.sum;
    ans.pref=max(left.pref,left.sum+right.pref);
    ans.suf=max(right.suf,right.sum+left.suf);
    ans.seg=max({left.seg,right.seg,left.suf+right.pref});
    return ans;
}

Node query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node];
    if(r<query_l || query_r<l) return Node(-1e18); 
    int mid=l+(r-l)/2;
    Node left=query(node*2, l, mid, query_l, query_r);
    Node right=query(node*2+1, mid+1, r, query_l, query_r);
    Node ans=merge(left,right);
    return ans;
}

void update(int idx, int val, int n){
    st[n+idx]=Node(val);
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=merge(st[2*i],st[2*i+1]);
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    while(__builtin_popcount(n) != 1){
        a.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++) st[n+i]=Node(a[i]);
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }

    cout<< max(0LL,st[1].seg) <<"\n";
    for(int i=0 ; i<m ; i++){
        int pos,val; cin >> pos >> val;
        update(pos, val, n);
        cout<< max(0LL,st[1].seg) <<"\n";
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