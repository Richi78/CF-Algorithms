#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];  
    for(int i=0 ; i<n ; i++) cin >> b[i];  
    k&=1;
    if(k){
        int mxB=-1 , mx=-1e18 , cur=0 , cur2=0;
        for(int i=0 ; i<n ; i++){
            cur+=a[i];
            mxB=max(mxB,b[i]);
            mx=max(mx,cur+mxB);
            if(cur+mxB < 0){
                cur=0; mxB=-1;
            }
            if(a[i]+b[i] > mx){
                cur=a[i]; mxB=b[i];
                mx=max(mx,cur+mxB);
            }
            debug1(mx)
        }
        cout<< mx <<"\n";
    }else{
        int mx=-1e18 , cur=0;
        for(int i=0 ; i<n ; i++){
            cur+=a[i];
            mx=max(mx,cur);
            if(cur<0) cur=0;
        }
        cout<< mx <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}