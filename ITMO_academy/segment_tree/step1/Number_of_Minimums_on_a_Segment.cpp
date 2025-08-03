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

vector<array<int,2>> st;

array<int,2> merge(array<int,2> &left, array<int,2> &right){
    if(left[0] < right[0]) return left;
    else if(right[0] < left[0]) return right;
    else return {left[0], left[1]+right[1]};
}

array<int,2> query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node];
    if(r<query_l || query_r<l) return {(int)1e18,1};
    int mid=l+(r-l)/2;
    array<int,2> left=query(node*2, l, mid, query_l, query_r);
    array<int,2> right=query(node*2+1, mid+1, r, query_l, query_r);
    return merge(left,right);
}

void update(int pos, int val, int n){
    st[n+pos]={val,1};
    for(int i=(n+pos)/2 ; i>=1 ; i>>=1){
        int l=st[2*i][0] , r=st[2*i+1][0];
        if(l<r) st[i]=st[2*i];
        else if(r<l) st[i]=st[2*i+1];
        else st[i]={l,st[2*i][1]+st[2*i+1][1]};
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
    for(int i=0 ; i<n ; i++) st[n+i]={a[i],1};
    for(int i=n-1 ; i>=1 ; i--){
        int l=st[2*i][0] , r=st[2*i+1][0];
        if(l<r) st[i]=st[2*i];
        else if(r<l) st[i]=st[2*i+1];
        else st[i]={l,st[2*i][1]+st[2*i+1][1]};
    }

    for(int i=0 ; i<m ; i++){
        int type; cin >> type;
        if(type == 1){
            int pos,val; cin >> pos >> val;
            update(pos,val,n);
        }else{
            int a,b; cin >> a >> b;
            array<int,2> ans=query(1,0,n-1,a,b-1);
            cout<< ans[0] <<" "<< ans[1] <<"\n";
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