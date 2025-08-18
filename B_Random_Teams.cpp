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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    if(m == 1){
        int ans=n*(n-1)/2;
        cout<< ans <<" "<< ans <<"\n";
        return;
    }
    int mx=(n-m+1)*(n-m)/2;

    int cntGroups=(n+m-1)/m;
    int tmp=n%m==0?m:n%m;
    int mn=tmp*cntGroups*(cntGroups-1)/2;
    if(n%m != 0){
        tmp=m-n%m;
        mn+=tmp*(n/m)*(n/m-1)/2;
    }
    cout<< mn <<" "<< mx <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

