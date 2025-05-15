#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    string s="aeiou";
    string ans="";
    int cnt=n/5 , tmp = n%5;

    for(int i=0 ; i<5 ; i++){
        if(tmp) {
            string x=string(cnt+1,s[i]);
            ans+=x;
            tmp--;
        }else {
            string x=string(cnt, s[i]);
            ans+=x;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}