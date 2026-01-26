#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,d,h; cin >> n >> d >> h;
    if(d>2*h || n<=d || (h==1 && d==1 && n!=2)){
        cout<<"-1\n"; return;
    }
    for(int i=0 ; i<d;  i++){
        if(i==h) cout<<"1 "<< i+2 <<"\n";
        else cout<< i+1 <<" "<< i+2 <<"\n";
    }
    for(int i=d+1 ; i<n ; i++){
        cout<< h <<" "<< i+1 <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}