#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int x; cin >> x;
    int sum=x;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        sum+=a[i];
    }

    int r=sum%n;
    vector<int> f(n);
    for(int i=0 ; i<n ; i++){
        f[i]=sum/n;
        if(r) f[i]++,r--;
    }
    sort(all(a));
    reverse(all(a));
        
    int ans=1;
    for(int i=0 ; i<n ; i++){
        int l=i-1 , r=n;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(a[i] > f[mid]) r=mid;
            else l=mid;
        }
        if(l==i-1) ans*=0;
        else ans= ans * (l - i + 1) %MOD;
    }

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}