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
    vi a(n);
    map<int,int> mp;
    forn(i,n){
        cin>>a[i];
        mp[a[i]]+=1;
    }
    vi aa;
    for(auto [m,cant]:mp){
        aa.pb(cant);
    }
    sort(all(aa));
    int ans=0,turn=1;
    for(auto x:aa){
        if(turn){
            if(x==1){ans+=2;turn=!turn;}
            else ans++;
        }else{
            if(x==1)turn=!turn;
            else ans++;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}