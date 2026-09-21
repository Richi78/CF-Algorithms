#include <bits/stdc++.h>

using namespace std;

#define int long long

class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0 ; i<n ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    int unionFind(int a, int b){
        int A=find(a) , B=find(b);
        if(A == B) return -1;
        if(size[A] < size[B]){
            parent[A]=B;
            size[B]+=size[A];
            return B;
        }else{
            parent[B]=A;
            size[A]+=size[B];
            return A;
        }
    }
};

struct Point{
    int x,y; 
    void read(){cin >> x >> y;}
    Point operator -(const Point &b) const{
        return Point{x-b.x , y-b.y};
    }
    int operator *(const Point &b) const{
        return x*b.y - y*b.x;
    }
    int cross(const Point &b, const Point &c) const{
        return (b-*this) * (c-*this);
    }
    bool operator <(const Point &b) const {
        return make_pair(x,y) < make_pair(b.x,b.y);
    }
};

vector<Point> convex(vector<Point> &points){
    sort(points.begin(), points.end());

    vector<Point> hull;
    for(int iter=0 ; iter<2 ; iter++){
        int S=hull.size();
        for(const Point &c : points){
            while((int)hull.size() >= S+2){
                Point a = hull.end()[-2] , b=hull.end()[-1];
                if(a.cross(b,c) < 0) break;
                hull.pop_back();
            }
            hull.push_back(c);
        }
        hull.pop_back();
        reverse(points.begin() , points.end());
    }
    return hull;
}

int area(const vector<Point> &a){
    int area=0;
    int n=a.size();
    for(int i=0 ; i<n ; i++){
        area += a[i] * a[(i+1)%n];
    }
    return labs(area);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;

    DSU dsu(n);

    map<int,vector<Point>> mp;
    for(int i=0 ; i<n ; i++){
        Point tmp; tmp.read();
        mp[i].push_back(tmp);
    }

    map<int,int> dp;
    for(int rep=0 ; rep<m ; rep++){
        int x,y; cin >> x >> y;
        x--; y--;

        int A=dsu.find(x) , B=dsu.find(y);
        int parent = dsu.unionFind(x,y);
        if(parent == -1){
            cout<< dp[A] <<"\n"; continue;
        }

        if(dsu.size[A] < dsu.size[B]){
            assert(parent==B);
            mp[B].insert(mp[B].end() , mp[A].begin() , mp[A].end());
        }else{
            assert(parent==A);
            mp[A].insert(mp[A].end() , mp[B].begin() , mp[B].end());
        }
        vector<Point> hull = convex(mp[parent]);
        int ans = area(hull);
        dp[parent] = ans;
        cout<< ans <<"\n";
    }
}