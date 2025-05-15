#include <bits/stdc++.h>

using namespace std;

#define int long long int 
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
#define SIZE 100000

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k;cin>>n>>k;
    map<int,int> mp;
    forn(i,n){
        int x;cin>>x;mp[x]++;
    }
    vi a;
    for(auto [x,y]:mp)a.pb(y);
    sort(all(a));
    int i=0,ans=mp.size();
    while(k>0){
        k=k-a[i];
        i++;      
        ans--;  
    }
    if(k<0)ans++;
    cout<<max(ans,1LL)<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}