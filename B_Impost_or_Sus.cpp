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
    string s; cin >> s;
    int ans=0;
    if(s[0] == 'u') ans++,s[0]='s';
    int sz=s.size();
    for(int i=1 ; i<sz ; i++){
        if(s[i] == 's') continue;
        if(i+1<sz && s[i+1]=='u') ans++, s[i+1]='s';
    }
    if(s[sz-1] == 'u') ans++;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}