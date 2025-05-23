#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a[i]={x,y};
    }
    int x,y,z,w; cin >> x >> y >> z >> w;
    int r1= (x-z)*(x-z) + (y-w)*(y-w); 
    for(auto [p,q] : a){
        int r2=(p-z)*(p-z) + (q-w)*(q-w);
        // debug2(r1,r2)
        if(r2 <= r1){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

