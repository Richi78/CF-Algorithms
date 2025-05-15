#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
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
    int n; cin >> n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    int debt=0 , mn=1e9+7;
    for(int i=0 ; i<n ; i++){
        int x=a[i] , y=b[i];
        if(x == y){
           mn=0; 
        }else if(x < y){
            if(debt) {cout<<"NO"<<endl; return;}
            debt=y-x;
        }else{
            mn=min(mn,x-y);
        }
    }
    if(mn>=debt) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}