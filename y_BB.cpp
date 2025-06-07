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
    int x=a.x-b.x , y=a.y-b.y;
    return sqrt(x*x + y*y);
}

bool intersec(Circle &a, Circle &b){
    double d=dist(a.center, b.center);
    if(a.r+b.r < d) return false; //no intersectan
    if(d+min(a.r,b.r) < max(a.r,b.r)) return false; // esta dentro
    if(a.r+b.r >= d) return true; //intersectan
}

void solve(int n, vector< Circle > &v){
    // double a,b,c;
    // vector< Circle > v;
    // for(int i=0 ; i<n ; i++){
    //     cin >> a >> b >> c;
    //     v.push_back(Circle(Point(a,b),c));
    // } 

    DisjointSet dsu(n);
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<n ; j++){
            if(i==j)continue;
            if(intersec(v[i],v[j])){
               dsu.unionBySize(i,j);
            }
        }
    }
    int mx=*max_element(all(dsu.size));
    cout<<"The largest component contains "<<mx<<" ring";
    cout<< (mx == 1 ? "" : "s") << "." <<endl;
}

signed main(){
    string line;
    getline(cin, line);
    istringstream ss(line);
    int n;
    ss >> n;
    while (n != -1) {
        double a,b,c;
        vector< Circle > v;
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> a >> b >> c;
            v.push_back(Circle(Point(a,b),c));
        }
        solve(n , v);

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}

// bool intersect( const vector< pair< float, pair<float, float> > > &v, int i, int j) {

//     float dx = v[i].S.F - v[j].S.F;
//     float dy = v[i].S.S - v[j].S.S;
//     float distance = sqrt(dx*dx + dy*dy);
//     double sum = v[i].F + v[j].F;
//     double diff = abs(v[i].F - v[j].F);
//     return ((distance <= sum) && (distance >= diff));
// }

// signed main(){

//     string line;
//     getline(cin, line);
//     istringstream ss(line);

//     int n;
//     ss >> n;
//     while (n != -1) {
//         vector< pair<float, pair<float, float> > > v(n);
//         for (int i = 0; i < n; ++i) {
//             getline(cin, line);
//             ss.clear();
//             ss.str(line);
//             ss >> v[i].S.F >> v[i].S.S >> v[i].F;
//         }

//         vector<int> p(n);
//         for (int i = 0; i < n; ++i) p[i] = i;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i+1; j < n; ++j) {
//                 if (p[i] != p[j] && intersect(v, i, j)) {
//                     int old = max(p[i], p[j]);
//                     int neu = min(p[i], p[j]);
//                     for (int k = 0; k < n; ++k)
//                         if (p[k] == old) p[k] = neu;
//                 }
//             }
//         }

//         vector<int> c(n);
//         int max = 0;
//         for (int i = 0; i < n; ++i) {
//             c[p[i]]++;
//             if (c[p[i]] > max) max = c[p[i]];
//         }

//         cout << "The largest component contains " << max << " ring";
//         cout << (max == 1 ? "":"s") << "." << endl;

//         getline(cin, line);
//         ss.clear();
//         ss.str(line);
//         ss >> n;
//     }
// }