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
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        mp[x]++;
    }
    int sum=0 , mx=0;
    for(auto [x,y] : mp){
        sum+=y; uax(mx,y);
    }
    cout<< sum - mx << endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

