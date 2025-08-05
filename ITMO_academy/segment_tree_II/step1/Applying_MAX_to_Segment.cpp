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

vector<int> st;

int query(int idx, int n){
    int ans=st[n+idx];
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        ans=max(ans,st[i]);
    }
    return ans;
}

void update(int node, int l, int r, int query_l, int query_r, int val){
    if(query_l<=l && r<=query_r){
        st[node]=max(st[node],val);
        return;
    }
    if(r<query_l || query_r<l) return;
    int mid=l+(r-l)/2;
    update(node*2, l, mid, query_l, query_r, val);
    update(node*2+1, mid+1, r, query_l, query_r, val);
}

void solve(){
    int n,m; cin >> n >> m;

    while(__builtin_popcount(n) != 1) n++;

    st.resize(2*n);

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            int l,r,val; cin >> l >> r >> val;
            update(1,0,n-1,l,r-1,val);
        }else{
            int pos; cin >> pos;
            cout<< query(pos,n) <<"\n";
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