#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
// #define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

struct Point{
    double x , y;
    Point (double x, double y): x(x) , y(y){}
};

double dist(Point a, Point b){
    int x=a.x-b.x , y=a.y-b.y;
    return sqrt(x*x + y*y);
}

pair<double, pair<pair<double,double>, pair<double,double>>> closest_pair(vector<pair<double,double>> pts, int n) {
    
    sort(all(pts));
    set<pair<double,double>> s;
 
    pair<double, pair<pair<double,double>, pair<double,double>>> best_dist = {1.0*1e9, {{-1, -1}, {-1, -1}}};
    int j = 0;
    for(int i = 0; i < n; ++i) {
        double d = ceil(sqrt(best_dist.F));
        while(j < n and pts[i].F - pts[j].F >= d) {
            s.erase({pts[j].S, pts[j].F});
            ++j;
        }
 
        auto it1 = s.lower_bound({pts[i].S - d, pts[i].F});
        auto it2 = s.upper_bound({pts[i].S + d, pts[i].F});
        
        for(auto it = it1; it != it2; ++it) {
            double dx = pts[i].F - it->S;
            double dy = pts[i].S - it->F;
            best_dist = min(best_dist, {dx * dx + dy * dy, {{it->S, it->F}, pts[i]}});      
        } 
        s.insert({pts[i].S, pts[i].F}); 
    }
    return best_dist;
}

void solve(){
    int n; cin >> n;
    vector<pair<double,double>> a(n);
    for(int i=0 ; i<n ; i++){
        double x,y; cin >> x >> y;
        a.emplace_back(x,y);
    }
    set<pair<int, int>> s;
    sort(all(a));

    pair<int, pair<pair<int,int>, pair<int,int>>> ans=closest_pair(a, n);

    cout<<ans.F<<endl;

}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();

}

