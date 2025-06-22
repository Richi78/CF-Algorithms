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
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    for(int i=0 ; i<s1.size() ; i++){
        if(s1[i]=='G' || s1[i]=='B') s1[i]='X';
        if(s2[i]=='G' || s2[i]=='B') s2[i]='X';
    }
    if(s1==s2)cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}