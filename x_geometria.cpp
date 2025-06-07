#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;


//------------PUNTO------------------------
struct Point{
    double x , y;
    Point (double x, double y): x(x) , y(y){}
    Point operator+(Point b) {return {x+b.x, y+b.y};}
    Point operator-(Point b) {return {x-b.x, y-b.y};}
    Point operator*(double d) {return {x*d, y*d};}
    Point operator/(double d) {return {x/d, y/d};}
    bool operator==(Point b) {return x==b.x && y==b.y;}
};

double dist(Point a, Point b){
    int x=a.x-b.x , y=a.y-b.y;
    return sqrt(x*x + y*y);
}

Point translate(Point v, Point p) {return p+v;} //mover un punto
Point scale(Point c, double factor, Point p) {return c+(p-c)*factor;} //escalar un punto respecto un centro y un factor
bool operator==(Point a, Point b) {return a.x==b.x && a.y==b.y;}
bool operator!=(Point a, Point b) {return !(a==b);}
//---------------------------------------------

//-------------LINEA---------------------
struct Line{
    Point v; double c;
    // From direction vector v and offset c
    Line (Point v, double c): v(v) , c(c) {}
    // From equation ax+by=c
    Line (double a, double b, double c): v({b,-a}), c(c) {} 
    // From points P and Q
    Line (Point p, Point q): v(q-p), c(cross(v,p)) {}
};
//-----------PRODUCTO-CRUZ-------------------
double cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
//---------------------------------------------

//--------------------PRODUCTO-PUNTO--------------
double dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

double abs(Point a){ //longitud
    return sqrt(dot(a,a));
}

double proj(Point a, Point b){ //proyeccion a sobre b
    return dot(a,b)/abs(b);
}

double angle(Point a, Point b){
    double ans = acos(dot(a,b) / abs(a) / abs(b)); //rad
    //ans *=180.0/M_PI
    return ans;
}
//---------------------------------------------

//--------------INTERSECCION-2-LINEAS-------------
Point inter(Line a, Line b){
    double d=cross(a.v, b.v);
    if(d==0) return Point(DBL_MAX,DBL_MAX); //son lineas paralelas
    Point ans = ( (b.v*a.c - a.v*b.c)/d );
    return ans;
}
//---------------------------------------------

//---------ORIENTATION--------------
double orient(Point a, Point b, Point c){
    return cross(b-a , c-a);
}
//---------------------------------------------

//--------------IS-IN-ANGLE------------------
bool inAngle(Point a, Point b, Point c, Point p){
    assert(orient(a,b,c) != 0);
    if(orient(a,b,c) < 0) swap(b,c);
    return orient(a,b,p) >= 0 && orient(a,c,p) <=0;
}
//---------------------------------------------

//--------------IS-CONVEX-----------------------
bool isConvex(vector<Point> &p){
    bool hasPos=false , hasNeg=false;
    for(int i=0 , n=p.size() ; i<n ; i++){
        int o=orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if(o > 0) hasPos=true;
        if(o < 0) hasNeg=true;
    }
    return !(hasPos && hasNeg);
}
//---------------------------------------------

//---------------CONVEX-HULL--------------------
int orientation(Point a, Point b, Point c){
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if(v < 0) return -1;
    if(v > 0) return +1;
    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear){
    int o=orientation(a,b,c);
    return o < 0 || (include_collinear && o==0);
}

bool collinear(Point a, Point b, Point c) {
    return orientation(a,b,c)==0;
}

void convex_hull(vector<Point> &a, bool include_collinear){
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b){
        return make_pair(a.y,a.x) < make_pair(b.y,b.x);
    });
    sort(a.begin(), a.end(), [&p0](const Point &a, const Point &b){
        int o = orientation(p0,a,b);
        if(o==0) 
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y); 
        return o<0;
    });
    if(include_collinear){
        int i = a.size()-1;
        while(i >= 0 && collinear(p0,a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<Point> st;
    for(int i=0 ; i<a.size() ; i++){
        while(st.size()>1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a=st;
}
//-------------------------------------------------



signed main(){
    
}