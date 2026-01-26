#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));
    int cur=1 , prev=0;
    for(int i=1 ; i<n ; i++){
        if(a[i]==a[i-1]) cur++;
        else if(a[i]-a[i-1]==1){
            if(cur>1) prev=cur;
            cur=1;
        }else cur=1 , prev=0;
        if(cur>=4 || (cur>=2 && prev>=2)){
            cout<<"YES\n"; return;
        }
    }
    cout<<"NO\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}