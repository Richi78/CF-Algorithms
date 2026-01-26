#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n) , b(m);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<m ; i++) cin >> b[i];
    vector<int> L(m+1,-1);
    for(int i=0 ; i<m ; i++){
        L[i+1]=L[i]+1;
        while(L[i+1]<n && a[L[i+1]]<b[i]) L[i+1]++;
    }
    vector<int> R(m+1,n);
    for(int i=m-1 ; i>=0 ; i--){
        R[i]=R[i+1]-1;
        while(R[i]>=0 && a[R[i]]<b[i]) R[i]--;
    }
    int ans=2e9;
    if(L[m]<n) ans=0;
    for(int i=0 ; i<m ; i++){
        if(L[i]+1 <= R[i+1]) ans=min(ans,b[i]);
    }
    if(ans == 2e9) ans=-1;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}