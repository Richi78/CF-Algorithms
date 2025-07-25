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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(int n, int m){
    if(n==m && n!=0 && m!=0){
        cout<<"1\n"; return;
    }

    if(n==0 || m==0){
        cout<< max(n,m) <<"\n"; return;
    }
    if(m>n) swap(n,m);
    
    int ans=(n+m)/(m+1);
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int n,m; 
    while(cin >> n >> m){
        if(n==-1 && m==-1) break;
        solve(n , m);
    }
}