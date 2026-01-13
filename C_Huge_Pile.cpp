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
    int n,k; cin >> n >> k;
    queue<pair<int,int>> q;
    q.push(make_pair(0,n));
    map<int,bool> vis;
    while(!q.empty()){
        int steps=q.front().first , val=q.front().second;
        q.pop();
        if(vis[val]) continue;
        if(val == k){
            cout<< steps <<"\n"; return;
        }
        vis[val]=true;
        if(val/2 >= k) q.push(make_pair(steps+1 , val/2 ));
        if((val+1)/2 >= k) q.push(make_pair(steps+1 , (val+1)/2 ));
    }    
    cout<<"-1\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}