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
    vector< vector<int> > a(n+1, vector<int>(2));
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a[x][y]++;
    } 
    int cnt=0 , j=0;
    for(int i=0 ; i<=n ; i++){
        if(a[i][j] && a[i][!j]) cnt+=n-2;
        if(i+1<=n && i-1>=0 && a[i][j] && a[i+1][!j] && a[i-1][!j]) cnt++;
        if(i+1<=n && i-1>=0 && a[i][!j] && a[i+1][j] && a[i-1][j]) cnt++;
    }
    cout<< cnt << "\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}