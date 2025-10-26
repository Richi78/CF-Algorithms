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

const int INF=1e18;

void solve(){
    int n; cin >> n;
    int mxX=-INF,mnX=INF,mxY=-INF,mnY=INF;
    for(int i=0 ; i<n ; i++){
        int x,y,h; cin >> x >> y >> h;
        uax(mxX,x+h);
        uax(mxY,y+h);
        uin(mnX,x-h); 
        uin(mnY,y-h);
    }
    int ans_x=(mxX+mnX)/2 , ans_y=(mxY+mnY)/2;
    int tmp=max(mxX-mnX,mxY-mnY);
    int ans_h=(tmp+1)/2;
    cout<< ans_x <<" "<< ans_y <<" "<< ans_h <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}