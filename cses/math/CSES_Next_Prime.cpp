#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

map<int,int> mp;

bool isPrime(int x){
    for(int i=2 ; i*i<=x ; i++){
        if(x%i == 0) return false;
    }
    return x>=2;
}

void solve(int n){
    int cur=n;
    while(!isPrime(cur+1)) cur++;
    for(int i=n ; i<=cur ; i++){
        mp[i]=cur+1;
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    vector<pair<int,int>> a(tc);
    for(int i=0 ; i<tc ; i++){
        int x; cin >> x;
        a[i]=make_pair(x,i);
    }
    sort(all(a));
    vector<int> ans(tc);
    for(int i=0 ; i<tc ; i++){
        if(!mp[a[i].first]){
            solve(a[i].first);
        }
        ans[a[i].second]=mp[a[i].first];
    }
    for(auto x : ans) cout<< x <<"\n";
}