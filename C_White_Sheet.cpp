#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int x3,y3,x4,y4; cin >> x3 >> y3 >> x4 >> y4;
    int x5,y5,x6,y6; cin >> x5 >> y5 >> x6 >> y6;

    //comprobar en x A2
    if(x4 <= x1){

    }else if(x4 >= x2){

    }else if(x1){

    }

    // comprobar en A3

}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

