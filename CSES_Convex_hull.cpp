#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<ll, ll>

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
        return Point{x-b.x , y-b.y};
    }
    int operator *(const Point &b) const {
        return x*b.y - y*b.x; 
    }
    int cross(const Point &b, const Point &c) const {
        return (b-*this) * (c-*this);
    }
    bool operator <(const Point &b) const {
        return make_pair(x,y)<make_pair(b.x,b.y);
    }
};

void solve(){
    int n; cin >> n;
    vector<Point> points(n);
    for(auto &x : points) x.read();

    sort(all(points));

    vector<Point> convex;

    for(int i=0 ; i<2 ; i++){
        const int S=convex.size();
        for(Point c : points){
            while((int)convex.size() >= S+2){
                Point a=convex.end()[-2] , b=convex.end()[-1];
                // check si esta a la izq
                if( a.cross(b,c) <= 0 ){ // <= para colinear
                    break;
                }
                convex.pop_back();
            }
            convex.push_back(c);
        }
        convex.pop_back();
        reverse(all(points));
    }
    cout<<(int)convex.size()<<"\n";
    for(auto c : convex){
        cout<< c.x << " " << c.y << "\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}