#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n;cin>>n;
    vector<vi> a(n,vi(n));
    forn(i,n){
        forn(j,n){
            int x;cin>>x;a[i][j]=x;
        }
    }
    int ans=0,minF=1e6,min;
    
    // forn(i,n){
    forn(j,n){ 
        forn(k,n){
            if(0+k<n && j+k<n){
                uin(minF,a[0+k][j+k]);
            }
        }
        if(minF<0)ans+=abs(minF);
        minF=1e6;
    }
    // }
    for(int i=1;i<n;i++){ 
        forn(k,n){
            if(i+k<n && 0+k<n){
                uin(minF,a[i+k][0+k]);
            }
        }
        if(minF<0)ans+=abs(minF);
        minF=1e6;
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}
