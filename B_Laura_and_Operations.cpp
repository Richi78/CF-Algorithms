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
    int a,b,c; cin >> a >> b >> c;
    int aa=1,bb=1,cc=1;
    if(abs(b-c) & 1) aa = 0;
    
    if (abs(a-c) & 1) bb = 0;
    
    if (abs(a-b) & 1) cc = 0;

    cout<< aa << " " << bb << " " << cc<<endl;

}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}