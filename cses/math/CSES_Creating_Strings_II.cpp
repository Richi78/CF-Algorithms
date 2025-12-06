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
    string s; cin >> s;
    int n=s.size();
    vector<int> fact(n+1,1);
    vector<int> invFact(n+1,1);

    for(int i=2 ; i<=n ; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0 ; i<=n ; i++){
        invFact[i]=binexp(fact[i],MOD-2);
    }

    vector<int> freq(26);
    for(int i=0 ; i<n ; i++){
        freq[s[i]-'a']++;
    }
    int ans= fact[n];
    for(int i=0 ; i<26 ; i++){
        ans= (ans * invFact[freq[i]])%MOD;
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