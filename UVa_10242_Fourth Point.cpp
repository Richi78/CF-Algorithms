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
    double x , y;
    Point (double x, double y): x(x) , y(y){}
    Point operator+(Point b) {return {x+b.x, y+b.y};}
    Point operator-(Point b) {return {x-b.x, y-b.y};}
    Point operator*(double d) {return {x*d, y*d};}
    Point operator/(double d) {return {x/d, y/d};}
    bool operator==(Point b) {return x==b.x && y==b.y;}
};

void solve(){
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cout<< setprecision(3) <<fixed;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
        Point a(x1,y1) , b(x2,y2) , c(x3,y3) , d(x4,y4);
        double x,y;
        if(a == c){
            x = b.x + d.x - a.x;
            y = b.y + d.y - a.y;
        }else if(a == d){
            x = b.x + c.x - a.x;
            y = b.y + c.y - a.y;
        }else if(b == c){
            x = a.x + d.x - b.x;
            y = a.y + d.y - b.y;
        }else if(b == d){
            x = a.x + c.x - b.x;
            y = a.y + c.y - b.y;
        } 
        cout<< x << " " << y <<endl;
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}