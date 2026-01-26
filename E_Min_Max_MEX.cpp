#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int check(vector<int> &a, int mex){
    int ans=0; set<int> st;
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] < mex) st.insert(a[i]);
        if(st.size() == mex) ans++ , st.clear();
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    int l=-1 , r=n/k + 1;
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(check(a,mid) >= k){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<< l <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}

