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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];
    vector<pair<int,int>> ans;
    for(int j=0 ; j<n ; j++){
        for(int i=0 ; i+1<n ; i++){
            if(a[i] > a[i+1]){
                swap(a[i],a[i+1]);
                ans.emplace_back(1,i+1);
            }
            if(b[i] > b[i+1]){
                swap(b[i],b[i+1]);
                ans.emplace_back(2,i+1);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(a[i] > b[i]){
            swap(a[i],b[i]);
            ans.emplace_back(3,i+1);
        }
    }
    cout<< ans.size() <<"\n";
    for(auto [x,y] : ans) cout<< x <<" " << y <<"\n";

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}