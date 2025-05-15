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
    vi a(n),b;
    set<int> prev;
    forn(i,n){
        cin>>a[i];
        if(i==0){
            if(a[i])b.pb(1);
            else b.pb(0);
        } else{
            if(a[i-1] && a[i]==0)b.pb(0);
            else if(a[i-1]==0 && a[i])b.pb(1);
        }
    }
    // printv(b);
    if(count(all(a),0)==n){cout<<0<<endl;return;}
    if(count(all(a),0)==0){cout<<1<<endl;return;}
    if(count(all(b),1)>1){cout<<2<<endl;return;}
    else cout<<1<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}