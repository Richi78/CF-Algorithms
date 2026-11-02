#include <bits/stdc++.h>

using namespace std;

struct Point{
  long double x,y;
  void read(){cin >> x >> y;}
  Point operator -(const Point &b) const {return Point{x-b.x , y-b.y};}
  long double operator *(const Point &b)const{return x*b.y - y*b.x;}
  long double cross(const Point &b, const Point &c) const {return (b-*this)*(c-*this);}
  long double dot(const Point &b, const Point &c) const{ return (b.x-x)*(c.x-x) + (b.y-y)*(c.y-y);}
  long double dist(const Point &b) const {return sqrtl((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));}
};

long double ans=1e9;

void calc(Point a, Point b, Point c){ // a,b hipotenusa
  long double r=a.dist(b)/2.0;
  Point m{(a.x+b.x)/2.0 , (a.y+b.y)/2.0};
  ans=min(ans, fabs(c.dist(m)-r));
  ans=min(ans, fabs(a.dot(b,c)) / a.dist(b) );
  ans=min(ans, fabs(b.dot(a,c)) / a.dist(b) );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout<< setprecision(10) <<fixed;

  Point P,Q,R;
  P.read(); Q.read(); R.read();

  calc(P,Q,R); calc(Q,R,P); calc(R,P,Q);

  cout<< ans <<"\n";
}