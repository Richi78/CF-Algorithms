#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int nCr(int n, int r){
    int ans=1;
    for(int i=1 ; i<=r ; i++){
        ans*=(n-i+1);
        ans/=i;
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> D(k+1);
    D[0]=1; D[1]=0;
    for(int i=2 ; i<=k ; i++){
        D[i]=(i-1)*(D[i-1]+D[i-2]);
    }
    int ans=0;
    for(int i=0 ; i<=k ; i++){
        int tmp=nCr(n,i)*D[i];
        ans+=tmp;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}