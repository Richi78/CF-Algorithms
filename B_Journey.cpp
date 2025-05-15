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
    int n,a,b,c;cin>>n>>a>>b>>c;
    int tmp=n/(a+b+c);
    int ans=0;
    if(tmp>=1){
        ans=tmp*3;
        n-=(a+b+c)*tmp;
    }

    vi turn={a,b,c};
    int i=0;
    while(n>0){
        ans++;
        n-=turn[i];
        i=(i+1)%3;
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}

// if(n>a){
//     ans++;
//     n-=a;
//     if(n>b){
//         ans++;
//         n-=b;
//         if(n>c){
//             ans++;
//             cout<<ans<<endl;
//         }
//     }else {
//         ans++;
//         cout<<ans<<endl;
//     }
// } else{
//     ans++;
//     cout<<ans<<endl;
// }