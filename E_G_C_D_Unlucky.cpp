#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int gcd(int a,int b){ return b==0?a:gcd(b,a%b);}

void solve(){
    int n; cin >> n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];    
    for(int i=0 ; i<n ; i++) cin >> b[i];    

    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        ans[i]=a[i]/gcd(a[i],b[i])*b[i];
    }
    int g=0;
    for(int i=0 ; i<n ; i++){
        g=gcd(g,ans[i]);
        if(g != a[i]){
            cout<<"NO\n"; return;
        }
    }
    g=0;
    for(int i=n-1 ; i>=0 ; i--){
        g=gcd(g,ans[i]);
        if(g != b[i]){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}