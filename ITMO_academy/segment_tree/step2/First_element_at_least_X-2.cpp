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

int query(int node, int l, int r, int val, int bound){
    if(st[node] < val) return -1;
    if(r < bound) return -1;
    if(l == r) return l;
    int mid=l+(r-l)/2;
    int left=query(node*2, l, mid, val, bound);
    if(left == -1)
        return query(2*node+1, mid+1, r, val, bound);
    return left;
}

void update(int idx, int val, int n){
    st[n+idx]=val;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=max(st[2*i],st[2*i+1]);
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
    for(int i=0 ; i<n ; i++) st[n+i]=a[i];
    for(int i=n-1 ; i>=1 ; i--) st[i]=max(st[2*i],st[2*i+1]);

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            // update
            int pos,val; cin >> pos >> val;
            update(pos,val,n);
        }else{
            // query
            int val,l; cin >> val >> l;
            cout<< query(1,0,n-1,val,l) <<"\n";
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