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

void ask(string &s, int x, int y){
    x--;
    s[x]=y;
    // cout<<s<<endl;
    for(int i=0 ; i<s.size()-3 ; i++){
        if(i<0)continue;
        if(i+3 >= s.size())continue;
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

void solve(){
    string s; cin >> s;
    int q; cin >> q;

    vector< pair<int, char> > a(q);
    for(int i=0 ; i<q ; i++){
        int x; char y; cin >> x >> y;
        pair<int,char> tmp={x,y};
        a[i]=tmp;
    }

    for(auto [x,y] : a){
        ask(s,x,y);
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}