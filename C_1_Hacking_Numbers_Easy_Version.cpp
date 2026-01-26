#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void add(int n){
    cout<< "add " << n <<endl;
    int x; cin >> x;
}

void solve(){
    int n; cin >> n;
    int x;
    cout<< "digit" <<endl;
    cin >> x;
    cout<< "digit" <<endl;
    cin >> x;
    add(-8); add(-4); add(-2); add(-1); add(n-1);
    cout<< "!" <<endl;
    cin >> x;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}