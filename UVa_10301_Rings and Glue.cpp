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

class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

struct Point{
    double x , y;
    Point (double x, double y): x(x) , y(y){}
    Point operator+(Point b) {return {x+b.x, y+b.y};}
    Point operator-(Point b) {return {x-b.x, y-b.y};}
    Point operator*(double d) {return {x*d, y*d};}
    Point operator/(double d) {return {x/d, y/d};}
    bool operator==(Point b) {return x==b.x && y==b.y;}
};

struct Circle{
    Point center;
    double r;
    Circle (Point c, double r): center(c) , r(r){}
};

double dist(Point &a, Point &b){
    double x=a.x-b.x , y=a.y-b.y;
    return sqrt(x*x + y*y);
}

bool intersec(Circle &a, Circle &b){
    double d=dist(a.center, b.center);
    if(a.r+b.r < d) return false; //no intersectan
    if(d+min(a.r,b.r) < max(a.r,b.r)) return false; // esta dentro
    if(a.r+b.r >= d) return true; //intersectan
}

void solve(int n){ //, vector< Circle > &v
    double a,b,c;
    vector< Circle > v;
    for(int i=0 ; i<n ; i++){
        cin >> a >> b >> c;
        v.push_back(Circle(Point(a,b),c));
    } 

    DisjointSet dsu(v.size());
    for(int i=0 ; i<v.size() ; i++){
        for(int j=i+1; j<v.size() ; j++){
            if(intersec(v[i],v[j])){
               dsu.unionBySize(i,j);
            }
        }
    }

    int mx=*max_element(all(dsu.size));
    cout<<"The largest component contains "<<(n==0 ? 0 : mx)<<" ring";
    if(n==0) cout<<"s."<<endl;
    else cout<< (mx == 1 ? "" : "s") << "." <<endl;
}

signed main(){
    int n;
    while(1){
        cin >> n;
        if(n == -1) break;
        solve(n);
    }
} 