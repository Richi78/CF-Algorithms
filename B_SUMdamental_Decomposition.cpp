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
    int n,x; cin >> n >> x;
    int bits=__builtin_popcountll(x) , ans;
    if(n == 1 && x == 0) ans=-1;
    else if(n <= bits) ans=x;
    else{
        int y = n - bits;
        // cout<< bits <<" y " << y <<endl;
        // cout<<x<<endl;
        
        if(y & 1){
            if(bits == 1){
                if(x&1)ans = x + y + 3;
                else ans = x + y + 1;
            }else if(bits > 1){
                ans = x + y + 1;
            }else{
                ans = x + y + 3;
            }
        }else{
            ans = x + y;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}