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

void f(int n, int from, int to, vector<pair<int,int>> &a){
    if(n == 1){
        a.emplace_back(from,to);
        return;
    }
    f(n-1, from, 6-from-to, a);
    // mover n a to
    a.emplace_back(from,to);
    f(n-1, 6-from-to, to, a);
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    f(n, 1, 3, a);

    cout<< a.size() <<"\n";
    for(auto [x,y] : a){
        cout<< x << " " << y << "\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}