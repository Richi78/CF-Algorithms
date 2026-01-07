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
    int n; cin >> n;
    string s; cin >> s;
    bool cur= (s[0]=='1');
    bool ok=true;
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        if(s[i] == '0') cnt++;
        if(i == 0) continue;
        if(s[i] == s[i-1] && s[i] == '0') cur=false;
        if(s[i] == s[i-1] && s[i] == '1'){
            if(cur && cnt&1) ok=false;
            cur=true;
            cnt=0;
        }
    }
    if(cur && cnt&1 && s[n-1]=='1') ok=false;
    cout<< (ok?"YES":"NO") <<"\n";    
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}