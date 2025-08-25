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

void solve(){
    int k; cin >> k;
    vector<vector<int>> a(k);
    vector<int> sum(k);
    for(int i=0 ; i<k ; i++){
        int n; cin >> n;
        vector<int> tmp(n);
        int s=0;
        for(int j=0 ; j<n ; j++){
            cin >> tmp[j];
            s+=tmo[j];
        }
        a[k]=tmp;
        sum[i]=s;
    }
    
    for(int i=0 ; i<k ; i++){
        for(int j=i+1 ; j<k ; j++){
            int delta=abs(s[i]-s[j]);
            for(int k=0; k<a[i].size() ; k++){
                
            }
        }
    }

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}