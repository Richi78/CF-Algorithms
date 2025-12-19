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
    int n,x; cin >> n >> x;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            int target=x-a[i]-a[j];
            if(mp.find(target) != mp.end()){
                for(auto idx : mp[target]){
                    if(idx!=i && idx!=j){
                        cout<< i+1 <<" "<< j+1 <<" "<< idx+1 <<"\n";
                        return;
                    }
                }
            }
        }
    }
    cout<< "IMPOSSIBLE\n"; 
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}