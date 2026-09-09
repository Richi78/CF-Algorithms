#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

struct Node{
    int val;
    int p2val;
    int lazy; // 
    Node(int x=0, int y=0, int z=0){ // LLONG_MAX means no op needed
        val=x; p2val=y; lazy=z;
    }
};

int BASE=1;
vector<Node> st;

void push(int node, int l, int r){
    if(st[node].lazy == 0) return;
    int x=st[node].lazy;
    st[node].p2val = ( st[node].p2val + 2*x%MOD*st[node].val%MOD + x*x%MOD*(r-l+1)%MOD ) % MOD;
    st[node].val = ( st[node].val + x*(r-l+1) ) % MOD;
    if(l != r){
        add_self(st[2*node].lazy , st[node].lazy);
        add_self(st[2*node+1].lazy , st[node].lazy);
    }
    st[node].lazy=0;
}

Node merge(Node& a, Node& b){
    Node ans;
    add_self( ans.val, (a.val + b.val) % MOD);
    add_self( ans.p2val, (a.p2val+b.p2val)%MOD );
    return ans;
}

void _update(int node, int l, int r, int ql, int qr, int val){
    push(node,l,r);
    if(qr<l || r<ql) return;
    if(ql<=l && r<=qr){
        add_self(st[node].lazy , val);
        push(node,l,r);
        return;
    }
    int mid=l+(r-l)/2;
    _update(node*2, l, mid, ql, qr, val);
    _update(node*2+1, mid+1, r, ql, qr, val);

    st[node].val = (st[node*2].val + st[node*2+1].val) % MOD;
    st[node].p2val = (st[node*2].p2val + st[node*2+1].p2val) % MOD;
}

int _query(int node, int l, int r, int ql, int qr){
    push(node, l, r);
    if(qr<l || r<ql) return 0;
    if(ql<=l && r<=qr){
        return st[node].p2val;
    }
    int mid=l+(r-l)/2;
    int left= _query(node*2, l, mid, ql, qr);
    int right= _query(node*2+1, mid+1,r,ql,qr);
    return (left+right)%MOD;
}

void update(int l, int r, int val){
    _update(1,0,BASE-1,l,r,val);
}

int query(int l, int r){
    return _query(1,0,BASE-1,l,r);
}

signed main(){
    int n,q; cin >> n >> q;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    while(BASE < n) BASE<<=1;
    
    st.resize(2*BASE);
    for(int i=0 ; i<n ; i++){
        Node tmp;
        tmp.val=a[i]; tmp.p2val=(a[i]*a[i])%MOD;
        st[i+BASE]=tmp;
    }
    for(int i=BASE-1 ; i>=1 ; i--){
        st[i]=merge(st[2*i],st[2*i+1]);
    }

    for(int rep=0 ; rep<q ; rep++){
        char type; cin >> type;
        if(type == 'u'){
            int l,r,val; cin >> l >> r >> val;
            update(l-1,r-1,(val+MOD)%MOD);
        }else{
            int l,r; cin >> l >> r;
            int ans=query(l-1,r-1);
            if(ans < 0) ans=(ans+MOD)%MOD;
            cout<< ans <<"\n";
        }
    }

}