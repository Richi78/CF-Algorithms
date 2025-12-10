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
const int N=1e6+2;
vector<int> fact(N);
vector<int> invFact(N);

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
    if(n&1){
        cout<<"0\n"; return;
    }
    // catalan number 1/n+1*binom{2n}{n}
    int new_N=n/2;
    int ans=( ( ( fact[2*new_N]*invFact[new_N] )%MOD * invFact[new_N] %MOD ) * binexp(new_N+1,MOD-2)) %MOD;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    fact[0]=1;
    for(int i=1 ; i<N ; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0 ; i<N ; i++){
        invFact[i]=binexp(fact[i],MOD-2);
    }
    solve();
}