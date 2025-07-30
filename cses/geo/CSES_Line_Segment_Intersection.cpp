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
    Point operator -(const Point &b) const {
        return Point{x-b.x , y-b.y};
    }
    int operator *(const Point &b) const {
        return x * b.y - y * b.x;
    }
    // cross respecto a this
    int cross(const Point &b, const Point &c) const {
        return (b - *this) * (c - *this);
    }
};

void solve(){
    vector<Point> a;
    for(int i=0 ; i<4 ; i++){
        Point x; x.read();
        a.push_back(x);
    }
    // paralelo o colinear
    if( (a[1]-a[0]) * (a[3]-a[2]) == 0 ){
        // parallel
        if( a[0].cross(a[1],a[2]) != 0 ){
            cout<<"NO\n"; return;
        }
        // colinear
        for(int i=0 ; i<2 ; i++){
            if(max(a[0].x,a[1].x) < min(a[2].x,a[3].x) || max(a[0].y,a[1].y) < min(a[2].y,a[3].y)){
                cout<<"NO\n"; return;
            }
            swap(a[0],a[2]);
            swap(a[1],a[3]);
        }
        cout<<"YES\n"; return;
    }
    // existe interseccion

    for(int i=0 ; i<2 ; i++){
        int x=a[0].cross(a[1],a[2]) , y=a[0].cross(a[1],a[3]);
        if( (x<0 && y<0) || (x>0 && y>0) ){
            cout<<"NO\n"; return;
        }
        swap(a[0],a[2]);
        swap(a[1],a[3]);
    }
    cout<<"YES\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}