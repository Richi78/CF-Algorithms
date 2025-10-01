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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int n; cin >> n;
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        mp[x]++;
    }    
    vector<pair<int,int>> a(all(mp));
    sort(all(a), [&](auto x, auto y){return x.second>y.second;});
    for(auto [x,y] : a){
        debug2(x,y)
    }
    int ans=a[0].second;
    int lcm=a[0].first;
    for(int i=1 ; i<a.size() ; i++){
        lcm=lcm/gcd(lcm,a[i].first)*a[i].first;
        if(mp[lcm] == 0){
            ans+=a[i].second;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}