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
    int n,m;cin>>n>>m;
    vi l(n);
    string s;
    forn(i,n){
        cin>>s;
        l[i]=s.size();
    }

    int ans=0,cnt=0;
    forn(i,n){
        if(cnt+l[i]>m)break;
        cnt+=l[i];
        ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}