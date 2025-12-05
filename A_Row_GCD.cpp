#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n) , b(m);
    for(int i=0 ; i<n ; i++) cin >> a[i]; 
    for(int i=0 ; i<m ; i++) cin >> b[i]; 

    int g=0;
    for(int i=1 ; i<n ; i++){
        g=gcd(g,abs(a[i]-a[0]));
    }
    for(int i=0 ; i<m ; i++){
        cout<< gcd(a[0]+b[i],g) <<" ";
    }
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