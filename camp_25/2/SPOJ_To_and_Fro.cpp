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
    string s; cin >> s;
    bool flag=0;
    for(int i=0 ; i<(int)s.size() ; i+=n){
        if(flag){
            reverse(s.begin()+i , s.begin()+i+n);
            flag=0;
        } else flag=1;
    }

    string ans="";
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<(int)s.size() ; j+=n){
            ans.push_back(s[j]);
        }
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