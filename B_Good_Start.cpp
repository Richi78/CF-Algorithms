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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}


void solve(){
    int w,h,a,b; cin >> w >> h >> a >> b;
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    
    cout<< (x1!=x2 && (x1-x2)%a==0 || y1!=y2 && (y1-y2)%b==0 ? "YES\n" : "NO\n");
    
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}