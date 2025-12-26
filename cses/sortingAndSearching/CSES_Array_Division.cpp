#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int check(vector<int> &a, int target){
    int groups=1;
    int sum=0;
    for(int i=0 ; i<(int)a.size() ; i++){
        if(a[i] > target) return 1e18;
        if(sum+a[i] <= target) sum+=a[i];
        else groups++,sum=a[i];
    }
    return groups;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    int l=0 , r=1e18;
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(check(a,mid) <= k){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<< r <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}