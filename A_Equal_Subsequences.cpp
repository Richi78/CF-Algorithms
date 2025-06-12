#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    string ans(n,'0');
    if(n<4 || k>n-2 || k==1 || k==0){
        for(int i=0 ; i<k ; i++){
            ans[i]='1';
        }
        cout<<ans<<"\n"; return;
    }
    int ones=k-1 , zeros=n-k-1;
    ans[0]='1';
    int i=1+zeros;
    while(ones){
        ans[i]='1'; 
        ones--; i++;
    }
    cout<<ans<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}