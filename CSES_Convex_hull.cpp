#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<ll, ll>

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
    int x , y;
    Point (int x, int y): x(x) , y(y){}
};


int orientation(Point a, Point b, Point c){
    long long v = 1LL*a.x*(b.y-c.y)
                + 1LL*b.x*(c.y-a.y)
                + 1LL*c.x*(a.y-b.y);
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

void solve(){
    int n; cin >> n;
    vector<Point> points;
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        points.emplace_back(x,y);
    }

    convex_hull(points , true);

    cout<<points.size()<<endl;
    for(int i=0 ; i<points.size() ; i++){
        cout<<points[i].x<< " " <<points[i].y<<endl;
    }
}

int main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
    return 0;
}