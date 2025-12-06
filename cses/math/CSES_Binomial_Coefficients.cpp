#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD=1e9+7;
const int N=1e6+10;
vector<int> fact(N,1);
vector<int> invFact(N,1);

int binexp(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,r; cin >> n >> r;
    int ans= ( ( (fact[n]*invFact[r])%MOD ) * invFact[n-r] )%MOD;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    for(int i=2 ; i<N ; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0 ; i<N ; i++){
        invFact[i]=binexp(fact[i],MOD-2);
    }
    int tc;cin>>tc;
    while(tc--)solve();
}