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
    int m,a,b,c;cin>>m>>a>>b>>c;
    int ans=0,r1=m,r2=m;

    if(r1>a){
        ans+=a;r1-=a;
    } else{
        ans+=r1;r1=0;
    }
    if(r2>b){
        ans+=b;r2-=b;
    }else{
        ans+=r2;r2=0;
    }
    if(r1+r2>c){
        ans+=c;
    } else{
        ans+=(r1+r2);
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}