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
    string l,r; cin >> l >> r;
    if(l == r){
        cout<< 2*l.size() <<"\n"; return;
    }
    int idx=0;
    while(idx<l.size() && l[idx]==r[idx]) idx++;
    int ans=2*idx;
    if(r[idx] - l[idx] > 1){
        cout<< ans <<"\n"; return;
    }
    ans++;
    for(int i=idx+1 ; i<l.size() ; i++){
        if(l[i] == '9' && r[i] == '0') ans++;
        else break;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}