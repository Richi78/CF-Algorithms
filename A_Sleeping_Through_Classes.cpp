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
    int n,m; cin >> n >> m;
    string s; cin >> s;
    int cur=0;
    int ans=0;
    for(int i=0 ; i<n ; i++){
        if(cur){
            if(s[i] == '1'){
                cur=m;
            }else{
                cur--;
            }
        }else{
            if(s[i] == '1'){
                cur=m;
            }else{
                ans++;
            }
        }
    }
    cout<< ans << "\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}