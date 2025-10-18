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

int query(int l, int r, int type){
    int ans;
    cout<< type << " " << l << " " << r <<endl;
    cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;

    int total_mod=query(1,n,2);
    int diff=total_mod - ((n*(n+1))/2);
    
    int cur_l;
    {
        // looking for l
        int l=1 , r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ori=query(1,mid,1);
            int mod=query(1,mid,2);
            if(ori == mod){
                l=mid+1;
                cur_l=mid;
            }else{
                r=mid-1;
            }
        }
    }
    cout<< "! " << cur_l+1 << " " << cur_l+diff <<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}