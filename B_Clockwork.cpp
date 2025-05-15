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
    int n,f=1;cin>>n;
    vi nums(n);
    forn(i,n){
        cin>>nums[i];
        if(nums[i]<=(n-1-i)*2 || nums[i]<=i*2){
            f=0;
        }
    }
    cout<<(f?"YES":"NO")<<endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int tc;cin>>tc;
    while(tc--)solve();
}