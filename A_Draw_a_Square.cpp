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
#define F first 
#define S second
#define pii pair<int,int>
#define SIZE 100000

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

signed main(){
    int tc;cin>>tc;
    while(tc--){
        int l,r,d,u;cin>>l>>r>>d>>u;
        if(abs(d-l)==abs(d-r) && abs(u-d)==abs(u-r) && abs(r-l)==abs(u-d))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}