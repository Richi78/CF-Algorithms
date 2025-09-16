#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    
    vector<bool> vis(n);
    for(int i=0 ; i<n ; i++){
        if(a[i]>=0){
            a[i]=-a[i]-1;
            vis[i]=true;
        } 
    }
    int mx_pos=-1e18 , idx_pos=-1;
    int mx_neg=-1e18 , idx_neg=-1;
    for(int i=0 ; i<n ; i++){
        if(vis[i]){
            // pos -> neg
            if(uax(mx_pos,-a[i]-1)) idx_pos=i;
        }else{
            // neg
            if(uax(mx_neg,-a[i]-1)) idx_neg=i;
        }
    }
    // debug2(mx_pos, mx_neg)
    // debug2(idx_pos,idx_neg)
    if(n&1){
        if(mx_neg >= mx_pos){
            a[idx_neg]=-a[idx_neg]-1;
        }else{
            a[idx_pos]=-a[idx_pos]-1;
        }
    }
    for(auto x : a) cout<< x <<" ";
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