#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define all(v) v.begin(),v.end()

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(3);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        if(x<0) a[0]++;
        else if(x==0)a[1]++;
        else a[2]++;
    }

    int ans=a[1];
    if(a[0]&1) ans+=2;
    cout<< ans <<"\n";
}
signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
    // solve();
}