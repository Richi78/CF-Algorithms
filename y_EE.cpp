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
#define PI acosl((ld)-1.0)

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    ld x1,y1,r1,x2,y2,r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    cout << setprecision(15) << fixed;

    // calcular el distancia de c1 a c2
    ld dx=x1-x2 , dy=y1-y2;
    ld d=sqrt(dx*dx + dy*dy);
    
    // verificar si hay interseccion
    if(r1+r2 <= d){
        cout<<0.0<<endl; return;
    }

    // verificar si uno esta completamente dentro de otro
    if(d+min(r1,r2) <= max(r1,r2)){
        cout<< (PI * min(r1,r2)*min(r1,r2)) <<endl; return;
    }

    // realmente se intersectan
    ld d1 = (r1*r1 - r2*r2 + d*d) / ((ld)2*d);
    ld d2 = (r2*r2 - r1*r1 + d*d) / ((ld)2*d);

    ld angle1 = acosl(d1 / r1);
    ld angle2 = acosl(d2 / r2);

    ld sc1 = (angle1 * r1*r1); 
    ld sc2 = (angle2 * r2*r2); 

    ld triangle1 = r1 * sinl(angle1) * d1;
    ld triangle2 = r2 * sinl(angle2) * d2;

    ld area1 = sc1 - triangle1;
    ld area2 = sc2 - triangle2;

    cout<< area1+area2 <<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}