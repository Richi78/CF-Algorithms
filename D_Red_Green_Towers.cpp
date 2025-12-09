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

void solve(){
    int R,G; cin >> R >> G;
    int h=1;
    while( (h*(h+1)/2) <= R+G ) h++;
    h--;

    vector<int> dp(R+1) , dp_old(R+1);
    dp_old[0]=1;
    for(int level=1 ; level<=h ; level++){
        for(int red_used=0 ; red_used<=R ; red_used++){
            // Case 1: level is green
            dp[red_used] = dp_old[red_used];
        
            // Case 2: level is red
            if(red_used >= level){
                dp[red_used] = (dp[red_used] + dp_old[red_used - level]) % MOD;
            }
        }
        dp_old.swap(dp);
    }
    int total=h*(h+1)/2;
    int ans=0;
    for(int red_used=0 ; red_used<=R ; red_used++){
        int green_used = total-red_used;
        if(green_used <= G){
            ans = (ans + dp_old[red_used] ) % MOD;
        }
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