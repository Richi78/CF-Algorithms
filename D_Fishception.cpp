#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF=1e18+100;

struct Point{
    int x,y;
    Point(int a=0, int b=0){
        x=a; y=b;
    }
    Point operator -(const Point &b) const {
        return Point{x-b.x, y-b.y};
    }
    int dot(const Point &b) const {
        return x*b.x + y*b.y;
    }
    int cross(const Point &b) const {
        return x*b.y - y*b.x;
    }
};

bool isRectangle(vector<Point> p){
    vector<int> d;

    for(int i=0 ; i<4 ; i++){
        for(int j=i+1 ; j<4 ; j++){
            Point v = p[i] - p[j];
            d.push_back(v.dot(v));
        }
    }
    sort(d.begin(), d.end());
    if(d[0] == 0) return false;
    return d[0] == d[1] &&
           d[2] == d[3] &&
           d[4] == d[5] &&
           d[0] + d[2] == d[4];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<Point> p(n);
    for(auto &x : p)
        cin >> x.x >> x.y;
    vector<Point> sx = p;
    vector<Point> sy = p;
    sort(sx.begin(), sx.end(), [](Point a, Point b){ // ordenar por x
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    sort(sy.begin(), sy.end(), [](Point a, Point b){ // ordenar por y
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    vector<Point> cand;
    int mid = n/2;
    for(int i=mid-2 ; i<=mid+1 ; i++)
        cand.push_back(sx[i]);
    for(int i=mid-2 ; i<=mid+1 ; i++)
        cand.push_back(sy[i]);
    sort(cand.begin(), cand.end(), [](Point a, Point b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    cand.erase(
        unique(cand.begin(), cand.end(), [](Point a, Point b){
            return a.x == b.x && a.y == b.y;
        }),
        cand.end()
    );
    int ans = INF;
    int m = cand.size();
    for(int i=0 ; i<m ; i++){
        for(int j=i+1 ; j<m ; j++){
            for(int k=j+1 ; k<m ; k++){
                for(int l=k+1 ; l<m ; l++){
                    vector<Point> q = {cand[i], cand[j], cand[k], cand[l]};
                    if(!isRectangle(q))
                        continue;
                    Point a = q[1] - q[0];
                    Point b = q[2] - q[0];
                    int area = 0;
                    for(int i=0 ; i<4 ; i++){
                        for(int j=i+1 ; j<4 ; j++){
                            for(int k=j+1 ; k<4 ; k++){
                                Point a = q[j] - q[i];
                                Point b = q[k] - q[i];

                                if(a.dot(b) == 0)
                                    area = max(area, abs(a.cross(b)));
                            }
                        }
                    }
                    if(area)
                        ans = min(ans, area);
                }
            }
        }
    }
    cout << ans << '\n';
}