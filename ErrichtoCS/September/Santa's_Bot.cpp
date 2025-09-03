#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MOD=998244353;
const int N=1e6+10;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a[n];
    vector<int> freq(N), inv_sz(N);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        for(int j=0 ; j<x ; j++){
            int y; cin >> y;
            a[i].push_back(y); 
            freq[y]++;
        }
        if(inv_sz[x] == 0){
            inv_sz[x]=binexp(x,MOD-2);
        }
    }
    int inv_n=binexp(n,MOD-2);
    int ans=0;
    for(int kid=0 ; kid<n ; kid++){
        int sz=a[kid].size();
        for(int toy=0 ; toy<sz ; toy++){
            int c=(freq[a[kid][toy]] * inv_n)%MOD;
            ans=(ans+((inv_n * inv_sz[sz])%MOD * c)%MOD)%MOD;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    solve();
}