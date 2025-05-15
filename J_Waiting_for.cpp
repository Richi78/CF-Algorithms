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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    char c;
    int n;
    cin>>c>>n;

}

signed main(){
    int tc;cin>>tc;
    int b=0,p=0;
    while(tc--){
        char e;int n;cin>>e>>n;
        if(e=='P'){
            p+=n;
        } else{
            b=n;
            if(b>p)yes;
            else no;
            p=(p-b)<0?0:p-b;
        }
    }
}