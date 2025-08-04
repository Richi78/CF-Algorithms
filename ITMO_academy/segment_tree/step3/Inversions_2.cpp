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

int query(int node, int l, int r, int k){
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(st[node*2] > k)
        return query(node*2, l, mid, k);
    return query(node*2+1, mid+1, r, k-st[node*2]);
}

void update(int idx, int n){
    st[n+idx]=0;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=st[2*i]+st[2*i+1];
    }
}

void solve(){
    int n; cin >> n;
    int tmp=n;
    vector<int> inv(n);
    for(int i=0 ; i<n ; i++) cin >> inv[i];

    vector<int> a(n,1);
    while(__builtin_popcount(n) != 1){
        a.push_back(0); n++;
    }

    st.resize(2*n);
    for(int i=0 ; i<n ; i++) st[n+i]=a[i];
    for(int i=n-1 ; i>=1 ; i--) st[i]=st[2*i]+st[2*i+1];

    vector<int> ans(tmp);
    for(int i=tmp-1 ; i>=0 ; i--){
        int x=query(1,0,n-1,tmp-inv[i]-1);
        ans[i]=x+1;
        update(x,n);
        tmp--;
    }
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}