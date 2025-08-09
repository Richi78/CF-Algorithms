#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int query(int l, int r){
    cout<< "1 " << (r-l+1) <<" 1 ";
    for(int i=l ; i<=r ; i++) cout<< i <<" ";
    cout<<endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    int max_dist=query(2,n);

    int l=2 , r=n;
    while(r-l+1 > 2){
        int mid=(l+r)/2;
        int left=query(l , mid);
        if(left == max_dist){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(r-l+1 == 2){
        int tmp=query(l,l);
        if(tmp != max_dist) l=r;
    }
    cout<< "1 " << n-1 << " " << l << " ";
    for(int i=1 ; i<=n ; i++) 
        if(i!=l) cout<< i <<" ";
    cout<<endl;
    int ans; cin >> ans;
    cout<< "-1 " << ans <<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}