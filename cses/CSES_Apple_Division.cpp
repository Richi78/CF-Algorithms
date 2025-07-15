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

int f(int idx, int cur, vector<int> &a, int sum){
    if(idx == 0){
        return abs(cur-(sum-cur));
    }

    int take=f(idx-1, cur+a[idx], a, sum);
    int notake=f(idx-1, cur, a, sum);

    return min(take, notake);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    int acc=accumulate(all(a),0LL);
    
    int ans=f(n-1, 0, a, acc);

    cout<< ans <<"\n";

    // iterando sobre los bitmasks
    // int mn=1e11;
    // for(int i=0 ; i<(1<<n) ; i++){
    //     int tmp=0;
    //     for(int j=0 ; j<n ; j++){
    //         if(i & (1<<j)) tmp+=a[j];
    //         else tmp-=a[j];
    //     }
    //     uin(mn,abs(tmp));
    // }
    // cout<< mn <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}