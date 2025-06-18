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
    vector< vector<int> > a(8, vector<int>(8));
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            char x; cin >> x;
            int z;
            if(x=='.')z=0;
            else if(x=='B')z=1;
            else if(x=='R')z=2;
            a[i][j]=z;
        }
    }

    for(int i=0 ; i<8 ; i++){
        if(a[i][0] != 2)continue;
        int tmp=2;
        bool ok=true;
        for(int j=0 ; j<8 ; j++){
            if(a[i][j] != tmp){
                ok=false; break;
            }
        }
        if(ok){
            cout<<"R\n"; return;
        }
    }
    for(int j=0 ; j<8 ; j++){
        if(a[0][j] != 1) continue;
        int tmp=1;
        bool ok=true;
        for(int i=0 ; i<8 ; i++){
            if(a[i][j] != tmp){
                ok=false; break;
            }
        }
        if(ok){
            cout<<"B\n"; return;
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}