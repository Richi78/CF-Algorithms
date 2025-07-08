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
    int n,m; cin >> n >> m;

    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];    

    int LOG=0;
    while((1<<LOG) <= n) LOG++;

    vector<vector<int>> st(n, vector<int>(LOG));

    for(int i=0 ; i<n ; i++){
        st[i][0]=a[i];
    }
    for(int j=1 ; j<LOG ; j++){
        for(int i=0 ; i+(1<<j)-1 < n ; i++){
            st[i][j]=min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    for(auto x: st){
        vdebug(x);
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}