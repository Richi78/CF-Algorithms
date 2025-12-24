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
    vector<int> a;
    int tmp=(1LL<<n)-1;
    vector<bool> vis(tmp+1);
    while(tmp){
        a.push_back(tmp);
        vis[tmp]=true;
        for(int i=1 ; i<1<<n ; i+=2){
            if(!vis[i] && ((tmp&i)==tmp)) a.push_back(i),vis[i]=true;
        }
        tmp -= ( 1LL << ( __builtin_popcountll(tmp) - 1 ) );
    }
    for(int i=0 ; i<vis.size() ; i+=2) a.push_back(i);
    for(auto e : a) cout<< e <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}