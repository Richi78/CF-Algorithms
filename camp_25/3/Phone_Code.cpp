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
    int n; cin >> n;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    int cnt=0;

    for(int col=0 ; col<(int)a[0].size() ; col++){
        char c=a[0][col];
        bool ok=true;
        for(int row=0 ; row<n ; row++){
            ok&=(c==a[row][col]);
        }
        if(ok) cnt+=ok;
        else break;
    }

    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}