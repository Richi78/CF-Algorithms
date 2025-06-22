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
    Point operator -(const Point &b) const {
        return Point{x-b.x, y-b.y};
    }
    int operator *(const Point &b) const {
        return x*b.y - y*b.x;
    }
    int cross(const Point &b, const Point &c) const {
        return (b-*this) * (c-*this);
    }
    bool operator ==(const Point &b) const{
        return x==b.x && y==b.y;
    }
};

struct Segment{
    Point ini,fin;
    void read(Point x, Point y){
        ini=x; fin=y;
    }
};

// 0->no inter   1->contain a point    2->inter
int inter(Point a, Point b, Point c, Point d){
    // son paralelos o colineales
    if( (b-a) * (d-c) == 0 ){
        return 0;
    }
    // verificar si existe interseccion
    for(int i=0 ; i<2 ; i++){
        int x=a.cross(b,c) , y=a.cross(b,d);
        if( (x<0 && y<0) || (x>0 && y>0) ){
            return 0;
        }
        swap(a,c);
        swap(b,d);
    }

    // existe interseccion, completa o contains?
    for(int i=0 ; i<2 ; i++){
        int x=a.cross(b,c) , y=a.cross(b,d);
        if( (x==0 && y) || (x && y==0) ){
            return 1;
        }
        swap(a,c);
        swap(b,d);
    }
    return 2;
}

void solve(){
    int n; cin >> n;
    vector<Segment> a(n);
    for(int i=0 ; i<n ; i++){
        Point x,y; x.read(); y.read();
        a[i].read(x,y);
    }

    int cnt=0;
    for(int i=0 ; i<n ; i++){

        for(int j=i+1 ; j<n ; j++){
            bool x=a[i].ini==a[j].ini ||
                a[i].ini==a[j].fin ||
                a[i].fin==a[j].ini ||
                a[i].fin==a[j].fin;
            if( x ){
                cnt++; continue;
            }
            int tmp=inter(a[i].ini,a[i].fin,a[j].ini,a[j].fin);
            if(tmp == 1){
                cnt+=2;
            }
            if(tmp == 2){
                cnt+=4;
            }
        }
    }
    cout << cnt <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}