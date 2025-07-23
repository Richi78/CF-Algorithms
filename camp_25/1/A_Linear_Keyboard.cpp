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

void solve(){
    string alpha,s; cin >> alpha >> s;
    vector<int> a(26);
    for(int i=0 ; i<26 ; i++){
        a[alpha[i]-'a']=i;
    }

    int cnt=0;
    for(int i=1 ; i<(int)s.size() ; i++){
        cnt+=abs(a[s[i]-'a'] - a[s[i-1]-'a']);
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}