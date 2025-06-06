#define _USE_MATH_DEFINES
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
#define ld long double

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

ld f(int x1, int y1, int r1, int x2, int y2, int r2){
    ld area1, area2, t;
    int dx=x1-x2;
    int dy=y1-y2;
    int dr=r1-r2;
    int d2=dx*dx+dy*dy;
    if(d2 >= (r1+r2)*(r1+r2)){
        return 0;
    }
    if(d2 <= dr*dr){
        return M_PI * min(r1,r2)*min(r1,r2);
    }
    ld d=sqrtl(d2);
    t = 2 * acosl((r1*r1+d2-r2*r2) / (2*r1*d));
    area1=t*r1*r1/2 - (r1*r1*sinl(t))/2;
    t=2*acosl((r2*r2+d2-r1*r1) / (2*r2*d));
    area2=t*r2*r2/2 - (r2*r2*sinl(t))/2;
    return area1+area2;
}

void solve(){
    cout << setprecision(17) << fixed;
    int x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ld ans=f(x1,y2,r1,x2,y2,r2);

    cout<< ans <<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}