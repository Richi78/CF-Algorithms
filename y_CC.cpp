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

void solve(){
    cout<< setprecision(3) << fixed;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
        double a,b;
        if(x1==x3 && y1==y3){
            a=x2+x4-x1;
            b=y2+y4-y1;
        }else if(x1==x4 && y1==y4){
            a=x2+x3-x1;
            b=y2+y3-y1;
        }else if(x2==x3 && y2==y3){
            a=x1+x4-x2;
            b=y1+y4-y2;
        }else {
            a=x1+x3-x2;
            b=y1+y3-y2;
        }
        cout<<a<<" "<<b<<endl;
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}