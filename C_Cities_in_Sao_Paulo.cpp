#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Point{
    int x,y;
    void read(){cin >> x >> y;}
    Point operator -(const Point &b) const {
        return Point{x-b.x , y-b.y};
    }
    //cross respecto al origen
    int operator *(const Point &b) const {
        return x*b.y - y*b.x;
    }
    //cross respecto a this
    int cross(const Point &b, const Point &c) const {
        return (b - *this) * (c - *this);
    }
};

bool intersect(Point a, Point b, Point c, Point d){ // linear segments intersection
    // check parallel or collinear
    if( (b-a) * (d-c) == 0 ){
        // check if parallel
        if(a.cross(b,c) != 0){
            return false;
        }
        // check if collinear, bounding box
        for(int i=0 ; i<2 ; i++){
            if(max(a.x,b.x)<min(c.x,d.x) || max(a.y,b.y)<min(c.y,d.y)){
                return false;
            }
            swap(a,c);
            swap(b,d);
        }
        return true;
    }
    for(int i=0 ; i<2 ; i++){
        int x=a.cross(b,c) , y=a.cross(b,d);
        if( (x<0 && y<0) || (x>0 && y>0)){
            return false;
        }
        swap(a,c);
        swap(b,d);
    } 
    return true;
}

bool contains(Point a, Point b, Point c){
    if( a.cross(b,c) == 0){
        return (min(a.x,b.x)<=c.x) && (c.x<=max(a.x,b.x))
            && (min(a.y,b.y)<=c.y) && (c.y<=max(a.y,b.y));  
    }
    return false;
}

void solve(){

  vector<Point> a={
    Point({x: 0, y:100}), 
    Point({x:100 , y:0}), 
    Point({x:200, y:0}), 
    Point({x:100, y:-100}), 
    Point({x:0,y:-100}), 
    Point({x:-100,y:0}),
    Point({x:-200,y:0}),
    Point({x:-100,y:100})
  };
  int n=a.size();
  

    int m; cin >> m;

    for(int i=0 ; i<m ; i++){
        Point p; p.read();      
        Point out= Point{p.x+1LL , 1'000'000'001LL};
        int cnt=0; 
        bool contain=false;
        for(int j=0 ; j<n ; j++){
            if( contains( a[j] , a[(j+1)%n] , p ) ){
                contain=true; break;
            }
            if( intersect( p , out , a[j] , a[(j+1)%n] ) ){
                cnt++;
            }
        }
        if(contain || cnt&1){
            cout<<"S\n";
        }else{
            cout<<"N\n";
        }
    }
}

signed main(){
    solve();
}