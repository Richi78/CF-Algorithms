#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;


void solve(){
    int n,k,q; cin >> n >> k >> q;
    vector<bool> mn(n+1) , mx(n+1);
    for(int i=0 ; i<q ; i++){
        int c,l,r; cin >> c >> l >> r;
        for(int j=l ; j<=r ; j++){
            if(c==1) mn[j]=true;
            else mx[j]=true;
        }
    }    
    for(int i=1 ; i<=n ; i++){
        if(mn[i] && mx[i]) cout<< k+1 <<" ";
        else if(mn[i]) cout<< k <<" ";
        else cout<< i%k <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}