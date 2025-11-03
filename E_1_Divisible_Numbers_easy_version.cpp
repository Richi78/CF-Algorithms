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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int a,b,c,d; cin >> a >> b >> c >> d;

    int ab=a*b;
    if(ab == 1){
        cout<< c <<" "<< d <<"\n";
        return;
    }
    int g=1;
    for(int x=a+1,y ; x<=c ; x++){
        g = gcd(x, ab);
        y = ab / g;
        y = ((b + y) / y) * y;
        if(y <= d){
            cout << x << " " << y << endl;
            return;
        }
    }
    
    cout<<"-1 -1\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}