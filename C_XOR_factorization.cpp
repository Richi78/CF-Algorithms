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
    int n,k; cin >> n >> k;
    
    if(k&1){
        for(int i=0 ; i<k ; i++) cout<< n <<" ";
        cout<<"\n"; return;
    }

    int idx=0;
    vector<int> ans(k);
    for(int i=30 ; i>=0 ; i--){
        if(n & (1LL<<i)){
            if(idx < k){
                for(int j=0 ; j<k ; j++)
                    if(idx != j) 
                        ans[j] |= (1LL << i);
                idx++;
            }else{
                for(int j=0 ; j+1<k ; j++)
                        ans[j] |= (1LL << i);
            }
        }else{
            for(int j=0 ; j<idx-(idx&1) ; j++){
                ans[j] |= (1LL << i);
            }
        }
    }
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}