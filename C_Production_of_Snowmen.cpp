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
    int n; cin >> n;
    vector<int> a(n) , b(n) , c(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];    
    for(int i=0 ; i<n ; i++) cin >> b[i];    
    for(int i=0 ; i<n ; i++) cin >> c[i];    

    int cur=0;
    for(int rot=0 ; rot<n ; rot++){
        bool ok=true;
        for(int j=0 ; j<n && ok ; j++){
            if(c[(j+rot)%n] <= b[j]) ok=false;
        }
        cur+=ok;
    }
    // debug1(cur)
    // n*cur rotaciones buenas para b y c

    int cur2=0;
    for(int rot=0 ; rot<n ; rot++){
        bool ok=true;
        for(int j=0 ; j<n && ok ; j++){
            if(b[(j+rot)%n] <= a[j]) ok=false;
        }
        cur2+=ok;
    }
    cout<< cur2*n*cur <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}