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
    int len=s.size();
    for(int i=1;i+1<len;i++){
        if(s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]){
            cout<<s[i-1]<<s[i]<<s[i+1]<<endl;
            return;
        } 
    }
    for(int i=1;i<len;i++){
        if(s[i-1]==s[i]){
            cout<<s[i]<<s[i]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}