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

int find(int node, int l, int r, int val){
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(st[node*2]>=val) return find(node*2, l , mid, val);
    return find(node*2+1, mid+1, r, val);
}

void update(int idx, int val, int n){
    st[n+idx]-=val;
    for(int i=(n+idx)/2; i>=1 ; i>>=1){
        st[i]=max(st[2*i],st[2*i+1]);
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> hotel(n);
    for(int i=0 ; i<n ; i++) cin >> hotel[i];

    while(__builtin_popcountll(n) != 1){
        hotel.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++) st[n+i]=hotel[i];
    for(int i=n-1 ; i>=1 ; i--) st[i]=max(st[2*i],st[2*i+1]);

    for(int i=0 ; i<m ; i++){
        int q; cin >> q;
        if(q > st[1]){
            cout<<"0 ";
            continue;
        } 
        int idx=find(1, 0, n-1, q);
        update(idx, q, n);
        cout<< idx+1 <<" ";
    }
    cout<< "\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}