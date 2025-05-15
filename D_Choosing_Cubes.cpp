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
    int n,f,k;cin>>n>>f>>k;
    vi a(n);
    forn(i,n)cin>>a[i];
    int fav=a[f-1];
    sort(all(a));
    if (n == k){
        cout << "YES" << '\n';
    }else if (a[n-k-1] < fav){
        cout << "YES" << '\n';
    }else if (a[n-k-1] > fav || a[n-k] > fav){
        cout << "NO" << '\n';
    }else{
        cout << "MAYBE" << '\n';
    } 
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}