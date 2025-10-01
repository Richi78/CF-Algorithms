#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int check(int pivot, vector<int> &a){
    int ans=0;
    int sz=a.size();
    for(int i=0 ; i<sz ; i++){
        ans+=llabs(a[i]-(pivot+i));
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int l=-3e5 , r=3e5;
    int ans=1e18;
    while(r-l>3){
        int tmp=(r-l)/3;
        int mid1=l+tmp , mid2=r-tmp;
        int left=check(mid1,a) , right=check(mid2,a);
        if(left < right){
            r=mid2-1;
        }else{
            l=mid1+1;
        }
    }
    for(int i=l ; i<=r ; i++){
        ans=min(ans, check(i,a));
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}