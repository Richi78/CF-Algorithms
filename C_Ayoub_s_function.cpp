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
 
void solve(){
    int n,m; cin >> n >> m;
    if(m == 0){
        cout<<"0\n"; return;
    }
    int total=n*(n+1)/2;
    int g1=(n-m)%(m+1);
    int g2=m+1-g1;
    int zeros1=n/(m+1);
    int zeros2=(n-m)/(m+1);
    cout<< total - ( (g1*zeros1*(zeros1+1)/2) + (g2*zeros2*(zeros2+1)/2) ) <<"\n";
}
 
signed main(){
    int tc; cin >> tc;
    while(tc--) solve();
}