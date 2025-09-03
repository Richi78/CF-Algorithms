#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int k=1e9;

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a.emplace_back(x,y);
    }    

    int c=-1e18 , z=-1e18;
    for(int i=0 ; i<n ; i++){
        c=max(c,a[i].first+a[i].second);
        z=max(z,a[i].first-a[i].second);
    } 

    int p,q;
    cout<< "? R " << k <<endl; 
    cin >> p;
    cout<< "? R " << k <<endl; 
    cin >> p;
    cout<< "? U " << k <<endl;
    cin >> p;
    cout<< "? U " << k <<endl;
    cin >> p;
    cout<< "? D " << k <<endl;
    cin >> q;
    cout<< "? D " << k <<endl;
    cin >> q;
    cout<< "? D " << k <<endl;
    cin >> q;
    cout<< "? D " << k <<endl;
    cin >> q;
    
    int x = (p + q - 8*k + c + z) / 2;
    int y = (p - q + c - z) / 2;

    cout<< "! " << x <<" "<< y <<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}