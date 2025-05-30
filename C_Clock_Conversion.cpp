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
    string s; cin >> s;
    string s1=s.substr(0,2) , s2=s.substr(3);
    int n1=stoi(s1) , n2=stoi(s2);
    bool am= n1<12 ? true : false;
    if(n1>12) n1-=12;
    else if(n1==0) n1=12;
    cout<<(n1<10 ? "0":"")<<n1<<":"<<(n2<10 ? "0":"")<<n2;
    cout<<(am ? " AM" : " PM")<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}