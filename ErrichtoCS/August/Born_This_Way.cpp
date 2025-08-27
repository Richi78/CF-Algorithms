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
    int n,m,ta,tb,k; cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n) , b(m);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<m ; i++) cin >> b[i];

    if(k>=n || k>=m){
        cout<<"-1\n"; return;
    }
    
    int ans=-1;
    for(int i=0 ; i<=k && i<n ; i++){
        auto it=lower_bound(all(b), a[i]+ta);
        if(it == b.end()){
            cout<<"-1\n"; return;
        }
        int idx=it-b.begin();
        if( idx+k-i < m ){
            ans=max(ans,b[idx+k-i]+tb); 
        }else{
            cout<<"-1\n"; return;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}