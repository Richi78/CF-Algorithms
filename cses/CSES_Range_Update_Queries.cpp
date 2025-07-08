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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

vector<int> st;

void update_range(int node, int l, int r, int query_l, int query_r, int v){
    if(query_l<=l && r<=query_r){
        st[node]+=v;
        return;
    }
    if(r<query_l || query_r<l){
        return;
    }
    int tmp=(l+r)/2;
    update_range(node*2, l, tmp, query_l, query_r, v);
    update_range(node*2+1, tmp+1, r, query_l, query_r, v);
}

int f(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<= query_r){
        return st[node];
    }
    if(r<query_l || query_r<l){
        return 0;
    }
    int tmp=(l+r)/2;
    int left=f(node*2, l, tmp, query_l, query_r);
    int right=f(node*2+1, tmp+1, r, query_l, query_r);
    return st[node]+left+right;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];

    while(__builtin_popcountll(n) != 1){
        a.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++){
        st[n+i]=a[i];
    }
    
    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){ //increase
            int l,r,v; cin >> l >> r >> v;
            update_range(1, 0, n-1, l-1, r-1, v);
        }else{ //query
            int pos; cin >> pos;
            cout<< f(1, 0, n-1, pos-1, pos-1) <<"\n";
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}