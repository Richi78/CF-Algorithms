#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<"\n";

const int MOD=998244353;
const int N=1e6+100;
vector<int> fact;
vector<int> invFact;

int binexp(long long a, long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1; 
    }
    return ans;
}

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

void solve(){
    int n,k; cin >> n >> k;
    int ans=0;
    // for(int i=n ; i>=k ; i--){
    //     int factor= ( (1LL * fact[i-1] * invFact[k-1])%MOD * invFact[i-1-(k-1)])%MOD;
    //     add_self(ans, (1LL * (n-i+1) * factor)%MOD );
    // }
    ans = (1LL * fact[n+1] * invFact[k+1])%MOD * invFact[n-k] %MOD;
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fact.resize(N);
    fact[0]=1;
    invFact.resize(N);
    invFact[0]=1;
    for(int i=1 ; i<N ; i++){
        fact[i] = (1LL*i*fact[i-1])%MOD;
    }
    invFact[N-1] = binexp(fact[N-1], MOD-2);
    for(int i = N-1; i >= 1; i--){
        invFact[i-1] = 1LL * invFact[i] * i % MOD;
    }
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}