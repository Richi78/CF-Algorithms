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
    int a,x,y,z,f; cin >> a >> x >> y >> z >> f;
    vector<int> av={x,y,z};
    sort(all(av));
    double avg= a*0.15 + ((av[1]+av[2])/2.0)*0.45 + f*0.4;

    if(avg > 50) cout<<"Si\n";
    else cout<<"No\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}