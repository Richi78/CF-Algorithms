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
    int n; cin >> n; 
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];

    set<int> st;
    vector<bool> vis(n+1);
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            vis[i]=true;
            int nxt=a[i];
            int tmp=1;
            while(nxt != i){
                vis[nxt]=true;
                tmp++;
                nxt=a[nxt];
            }
            st.insert(tmp);
        }
    }
    // get lcm with a*b/gcd(a,b) is incorrect with modulo
    // int l=1;
    // for(int i=0 ; i<x.size() ; i++){
        // int g=gcd(l,x[i]);
        // l=((l*x[i])%MOD * binexp(g,MOD-2) %MOD);
    // }
    // cout<< l <<"\n";

    // correct approach to calculate lcm with modulo is
    // find max exponent of each prime in the prime factorization
    // for each number, then multiply all p^max(e) % MOD
    map<int,int> mp;
    for(auto x : st){
        int tmp=x;
        for(int i=2 ; i*i<=tmp ; i++){
            int cnt=0;
            while(tmp%i == 0){
                cnt++;
                tmp/=i;
            }
            if(cnt){
                mp[i]=max(mp[i],cnt);
            }
        }
        if(tmp>1)mp[tmp]=max(mp[tmp],1LL);
    }
    int ans=1;
    for(auto [x,y] : mp){
        ans=(ans*binexp(x,y))%MOD;
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