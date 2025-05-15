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
    int ans=0,sum=0,layer=1;
    forn(i,n){
        cin>>a[i];
        sum+=a[i];
        while(sum>layer*layer){
            layer+=2;
        }
        if(sum==layer*layer){
            ans++; 
        }
        // cout<<"sum: "<<sum<<" layer: "<<layer<<endl;
    }
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}