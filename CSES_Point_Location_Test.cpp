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
    void read(){cin >> x >> y;}
    Point operator -(const Point& b) const {return Point{x-b.x, y-b.y};}
    void operator -=(const Point& b){ x-=b.x; y-=b.y;}
    int operator *(const Point& b) const {return x * b.y - y * b.x;}
    bool operator<(Point b){return x<b.x;}
};

void solve(){
    Point a,b,c;
    a.read(); b.read(); c.read();
    c-=a; 
    b-=a;
    int cross = c * b;
    if(cross < 0) cout<<"LEFT"<<"\n";
    else if(cross > 0) cout<<"RIGHT"<<"\n";
    else cout<<"TOUCH"<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}