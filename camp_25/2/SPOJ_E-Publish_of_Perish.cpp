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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(int n){
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int ans=0;
    for(int i=0 ; i<=1000 ; i++){
        int tmp=0;
        for(int j=0 ; j<n && tmp<i ; j++){
            if(a[j]>=i) tmp++;
        }
        if(tmp>=i) ans=i;
        else break;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int n;
    while(cin >> n){
        if(n == 0) break;
        solve(n);
    }
}