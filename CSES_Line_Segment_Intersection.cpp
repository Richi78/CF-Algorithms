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

struct Point{
    int x,y;
    void read(){cin>>x>>y;}
};
struct Line{
    Point x,y;
    long double m;
    Line (Point x, Point y): x(x),y(y){m=(long double)(y.y-x.y)/(long double)(y.x-x.x);}
};

void solve(){
    Point p1,p2,p3,p4;
    p1.read(); p2.read(); p3.read(); p4.read();
    Line l1(p1,p2) , l2(p3,p4);
    if(l1.m != l2.m) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}