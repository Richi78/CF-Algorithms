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
    map<int,set<int>> mp;
    int cntA=0 , cntB=0;
    for(int i=n-1 ; i>=0 ; i--){
        if(s[i] == 'a') cntA++;
        else cntB++;
        mp[cntA-cntB].insert(i);
    }
    
    int ans=1e18;
    if(mp.find(0)!=mp.end() && mp[0].lower_bound(0)!=mp[0].end()){
        ans=min(ans,*mp[0].lower_bound(0));
    }
    cntA=0; cntB=0;
    for(int i=0 ; i<n ; i++){
        if(s[i] == 'a') cntA++;
        else cntB++;
        if(cntA == cntB) ans=min(ans,n-(i+1));
        auto it=mp[-(cntA-cntB)].upper_bound(i);
        if(it!=mp[-(cntA-cntB)].end()){
            ans=min(ans,*it-(i+1));
        }
    }
    cout<< (ans==1e18?-1:ans) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}