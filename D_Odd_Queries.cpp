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
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        a[i]=a[i-1] + x;
    }

    for(int i=0 ; i<q ; i++){
        int x,y,z; cin >> x >> y >> z;
        int tmp1=a[x-1] , tmp2=a[n]-a[y];
        int ans = tmp1 + tmp2 + z * (y-x+1);
        if(ans&1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}