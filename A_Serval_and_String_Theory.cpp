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

void solve(){
    int n,k,f=1;
    string s;cin>>n>>k>>s;
    char c=s[0];
    if(n&1)c=s[(n/2)];
    forn(i,(n/2)){
        if(f && s[i]!=c)f=0;
        if(s[i]<s[n-1-i]){
            cout<<"YES"<<endl;return;
        } else if(s[i]>s[n-1-i]){
            if(k){
                cout<<"YES"<<endl;return;
            }else{
                cout<<"NO"<<endl;return;
            }
        }
    }
    //todos son iguales
    if(k and f==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}
