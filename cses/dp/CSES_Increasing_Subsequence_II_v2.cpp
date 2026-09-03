#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}
struct ST{
    int n=1;
    vector<int> st;
    ST(int sz){
        while(n<sz) n*=2;
        st.resize(2*n);
    } 
    void _update(int idx, int val){
        if(idx==0) return;
        add_self(st[idx],val);
        _update(idx/2, val);
    }
    int _query(int node, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr) return st[node];
        if(r<ql || qr<l) return 0;
        int mid=l+(r-l)/2;
        return (_query(node*2 ,l,mid, ql,qr) + _query(node*2+1,mid+1,r,ql,qr))%MOD;
    }
    void update(int idx, int val){
        _update(n+idx,val);
    }
    int query(int l, int r){
        return _query(1,0,n-1,l,r);
    }
};


int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> compressed(a.begin() , a.end());
    sort(compressed.begin(), compressed.end());
    compressed.resize( unique(compressed.begin() , compressed.end()) - compressed.begin()); 
    for(auto &x : a){
        x = lower_bound(compressed.begin() , compressed.end(), x) - compressed.begin();
    }

    ST st = ST(n);
    int ans=0;
    for(auto &x : a){
        int sum=1;
        if(x-1>=0)
            add_self(sum,st.query(0,x-1));
        add_self(ans,sum);
        st.update(x,sum);
    } 
    cout<< ans <<"\n";
    return 0;
}