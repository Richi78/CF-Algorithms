#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int check(vector<int> &a, int x){
    int ans=0;
    for(int i=0 ; i<a.size() ; i++){
        ans+=abs(a[i]-x);
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));

    int l=0 , r=1e10;
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(check(a,mid) < check(a,mid+1)){
            r=mid;
        }else{
            l=mid;
        }
    }

    cout<< check(a,r) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}