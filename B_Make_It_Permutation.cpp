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
    cout<< 2*n-1 <<endl;
    cout<< 1 << " " << 1 << " " << n <<endl;
    for(int i=2 ; i<=n ; i++){
        cout<< i << " " << 1 << " " << i-1 <<endl; 
        cout<< i << " " << i << " " << n <<endl; 

    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}