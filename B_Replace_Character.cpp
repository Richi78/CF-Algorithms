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


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    set<char> c;
    int mx=0,mn=1e10;
    char cmx,cmn;
    forn(i,n){
        int tmp=c.count(s[i]);
        if(tmp==0){
            int cnt=count(all(s),s[i]);
            if(uax(mx,cnt))cmx=s[i];
            if(uin(mn,cnt))cmn=s[i];
        }
    }
    if(cmx==cmn){
        char f=s[0];
        for(int i=0;i<n;i++){
            if(s[i]!=f){s[i]=f;break;}
        }
    }else{
        forn(i,n){
            if(s[i]==cmn){s[i]=cmx;break;}
        }
    }
    cout<<s<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}