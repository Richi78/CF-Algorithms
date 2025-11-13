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
    vector<vector<int>> a(2,vector<int>(n));
    vector<int> prefmn(n),prefmx(n),sufmn(n),sufmx(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[0][i];
        if(i==0){
            prefmn[i]=prefmx[i]=a[0][i];
        }else{
            prefmn[i]=min(prefmn[i-1],a[0][i]);
            prefmx[i]=max(prefmx[i-1],a[0][i]);
        }
    }
    for(int i=0 ; i<n ; i++) cin >> a[1][i];
    sufmn[n-1]=sufmx[n-1]=a[1][n-1];
    for(int i=n-2 ; i>=0 ; i--){
        sufmn[i]=min(sufmn[i+1],a[1][i]);
        sufmx[i]=max(sufmx[i+1],a[1][i]);
    }

    vdebug(prefmn)
    vdebug(prefmx)

    vdebug(sufmn)
    vdebug(sufmx)

    int ans=0;
    for(int i=0 ; i<n ; i++){
        // int mn=min(prefmn[i],sufmn[i]);
        // int mx=max(prefmx[i],sufmx[i]);
        // ans+=(2*n-mx+1);
    }
    cout<< ans <<"\n";

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}