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

int query(int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node];
    if(r<query_l || query_r<l) return 0;
    int mid=l+(r-l)/2;
    return query(node*2, l, mid, query_l, query_r)
        + query(node*2+1, mid+1, r, query_l, query_r);
}

void update(int idx, int n){
    st[n+idx]=1;
    for(int i=(n+idx)/2 ; i>=1 ; i>>=1){
        st[i]=st[2*i]+st[2*i+1];
    }
}

void solve(){
    int n; cin >> n;
    int tmp_n=n;
    vector<int> a(2*n);
    vector<vector<int>> pos(n+1);
    for(int i=0 ; i<2*n ; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    } 

    while(__builtin_popcount(2*n) != 1) n++;
    

    st.resize(4*n);
    vector<bool> vis(n+1);
    vector<int> ans(n+1);
    for(int i=0 ; i<(int)a.size() ; i++){
        if(!vis[a[i]]) vis[a[i]]=true;
        else{
            int l=pos[a[i]][0]+1 , r=pos[a[i]][1]-1;
            ans[a[i]]=0;
            if(l <= r){
                ans[a[i]]=query(1,0,2*n-1,l,r);
            }
            update(l-1,2*n);
            vis[a[i]]=true;
        }
    }
    for(int i=1 ; i<=tmp_n ; i++) cout<< ans[i] <<" ";
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