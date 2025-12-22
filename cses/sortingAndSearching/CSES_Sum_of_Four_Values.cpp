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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    map<int,vector<pair<int,int>>> mp;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            mp[a[i]+a[j]].emplace_back(i,j);
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            int target=k-a[i]-a[j];
            if(mp.find(target) != mp.end()){
                for(auto [x,y] : mp[target]){
                    if(i!=x && i!=y && j!=x && j!=y){
                        cout<< x+1 <<" "<< y+1 <<" "<< i+1 <<" "<< j+1 <<"\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}