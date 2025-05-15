#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string s;cin>>s;
    int a=s[0]-'0',b=s[2]-'0';
    char ans;
    if(s[1]=='<'){
        if(a<b)ans='<';
        else if(a==b)ans='=';
        else ans='>';
    }else if(s[1]=='>'){
        if(a>b)ans='>';
        else if(a==b)ans='=';
        else ans='<';
    }else{ //=
        if(a==b)ans='=';
        else if(a<b)ans='<';
        else ans='>';
    }
    cout<<a<<ans<<b<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}