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

void solve(){
    string s; cin >> s;
    int idx=-1;
    for(int i=0 ; i+1<s.size() ; i++){
        if(s[i]==s[i+1]) idx=i;
    }
    if(idx == -1) idx=0;
    string ans;
    
    char x=' ';
    for(int i=0 ; i<26 ; i++){
        int j=i+'a';
        if( (j != s[idx]) && (j != s[idx+1])){
            x=j; break;
        }
    }
    ans=s.substr(0,idx+1)+x+s.substr(idx+1);
    
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}