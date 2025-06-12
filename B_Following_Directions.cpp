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
    int n; cin >> n;
    string s; cin >> s;
    int x=0 , y=0 , a=1 , b=1;
    for(auto c : s){
        if(c == 'U')y++;
        else if(c == 'R')x++;
        else if(c == 'D')y--;
        else if(c == 'L')x--;
        if(x==a && y==b){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}