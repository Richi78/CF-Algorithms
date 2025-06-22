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
    int x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 == y1){
        cout<<"NO\n"; return;
    }
    for(int i=0 ; i<2 ; i++){
        bool ok = ((x2+x3)==x1 && y2==y3 && y1+y2==x1) ||
            (x2==x3 && x2==x1 && (y1+y2+y3)==x1); 
        if(ok){
            cout<<"YES\n"; return;
        } 
        swap(x1,y1);
        swap(x2,y2);
        swap(x3,y3);
    }
    cout<<"NO\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}