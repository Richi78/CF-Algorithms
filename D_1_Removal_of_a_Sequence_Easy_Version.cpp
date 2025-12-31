#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int getKth(int n,int x, int y){
    for(int i=0 ; i<x ; i++)
        n-=n/y;
    return n;
}

void solve(){
    int x,y,k; cin >> x >> y >> k;
    
    int l=0 , r=1e13;
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(getKth(mid,x,y) >= k) r=mid;
        else l=mid;
    }
    cout<< (r>1e12?-1:r) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}