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
        return Point{x-b.x , y-b.y};
    }
    int operator *(const Point &b) const {
        return x*b.y - y*b.x;
    }
    int cross(const Point &b, const Point &c) const {
        return (b-*this) * (c-*this);
    }
};

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n; cin >> n;
    vector<Point> a(n);
    for(auto &x : a) x.read();

    int boundary=0;
    for(int i=0 ; i<n ; i++){
        int x=abs(a[i].x-a[(i+1)%n].x) , y=abs(a[i].y-a[(i+1)%n].y);
        boundary+=gcd(x,y);
    }

    int area=0;
    for(int i=0 ; i<n ; i++){
        area+=a[i]*a[(i+1)%n];
    }
    area=abs(area);

    int inside=(area - boundary + 2) / 2;
    
    cout<<inside<<" "<<boundary<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}