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
    int n; cin >> n;
    vector<int> a(n);
    int odd=0 , even=0 , sum=0;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]=x;
        if(x & 1)odd++;
        else even++;
        sum+=x;
    }
    if(odd == n || even == n){
        cout<< *max_element(all(a)) << endl;
        return;
    } 
    int ans=sum - odd + 1;
    cout<<ans<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}