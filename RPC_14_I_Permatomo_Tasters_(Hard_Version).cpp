#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int f(vector<int> &a, int mid){
    int ans=0 , n=a.size();
    int j=n-1;
    for(int i=0 ; i<n ; i++){
        while(j>=0 && a[i]+a[j] > mid) j--;
        ans+=j+1;
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));

    int l=a[0]+a[0]-1 , r=a[n-1]+a[n-1]+1;
    // int l=-2e9-1LL , r=2e9;
    while(r-l > 1){
        int mid=l+(r-l)/2;
        if(f(a,mid) < k){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<< r <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}