#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

const int MOD = 1e9 + 7;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int mx=-1e10 , cur=0 , sum=0;
    for(int i=0 ; i<n ; i++){
        cur+=a[i] , sum+=a[i];
        if(cur > mx){
            mx=cur;
        }
        if(cur < 0){
            cur=0;
        }
    }
    
    // debug1(mx)
    if(mx < 0) mx=0;

    sum=(sum%MOD + MOD)%MOD;
    mx=mx%MOD;

    int factor=1;
    for(int i=0 ; i<k ; i++){
        factor = (factor * 2)%MOD;
    }
    // debug1(factor)
    int ans = sum + (mx * factor)%MOD -mx;
    cout<<(ans+MOD)%MOD<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

