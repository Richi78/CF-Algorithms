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

bool valid(long double mid, vector<pair<int,int>> &a, int w){
    long double prod=0;
    for(auto [p,t] : a){
        long double time=mid-2*t;
        if(time > 0){
            prod+= p*time;
        }
        if(prod >= w){
            return true;
        }
    }
    return false;
}

void solve(){
    int n,w; cin >> n >> w;
    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        int p,t; cin >> p >> t;
        a.emplace_back(p,t);
    }

    long double ans=0.0;
    long double l=0 , r=1e11L;
    long double eps=1e-8;
    while(r-l > eps){
        long double mid=l+(r-l)/2;
        if(valid(mid,a,w)){
            r=mid;
            ans=mid;
        }else{
            l=mid;
        }

    }
    // while(l <= r){
    // }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    cout<< setprecision(8) <<fixed;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}