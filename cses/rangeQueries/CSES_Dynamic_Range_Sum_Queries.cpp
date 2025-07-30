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

int f(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r){
        return st[node];
    }
    if(r<query_l || query_r<l){
        return 0;
    }
    int tmp=(l+r)/2;
    return f(node*2 , l, tmp, query_l, query_r) 
        + f(node*2+1, tmp+1, r, query_l, query_r);
}

void update_recursive(int node, int l, int r, int query_l, int query_r, int v){
    if(query_l<=l && r<=query_r){
        st[node]=v;
        return;
    }
    if(r<query_l || query_r<l){
        return;
    }
    int tmp=(l+r)/2;
    update_recursive(node*2, l, tmp, query_l, query_r, v);
    update_recursive(node*2+1, tmp+1, r, query_l, query_r, v);
    st[node]=st[node*2]+st[node*2+1];
}

void update_iterative(int pos, int v, int n){
    st[n+pos]=v;
    for(int i=(n+pos)/2 ; i>=1 ; i>>=1){
        st[i]=st[i*2]+st[i*2+1];
    }
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
    for(int i=n-1 ; i>=1 ; i--){
        st[i]=st[2*i]+st[2*i+1];
    }

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){ //update
            int pos,v; cin >> pos >> v;
            update_recursive(1, 0, n-1, pos-1, pos-1, v);
            // update_iterative(pos-1, v, n);
        }else{ //sum
            int l,r; cin >> l >> r;
            cout<< f(1, 0, n-1, l-1, r-1) <<"\n";
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}