#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

bool check(string &s, int i, int n){
    if(i+3 >= n) return false;
    if(i < 0) return false;
    if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') return true;
    else return false;
}

void solve(){
    string s; cin >> s;
    int cnt=0 , n=s.size();
    for(int i=0 ; i<s.size() ; i++){
        if(check(s,i,n)) cnt++;
    }

    int q; cin >> q;
    while(q--){
        int x; char y; cin >> x >> y;
        x--;
        int before=0,after=0;
        if(check(s,x-3,n) || check(s,x-2,n) || check(s,x-1,n) || check(s,x,n)) before=1;
        s[x]=y;
        if(check(s,x-3,n) || check(s,x-2,n) || check(s,x-1,n) || check(s,x,n)) after=1;
        cnt = cnt + after - before;
        cout<<(cnt ? "YES" : "NO")<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}