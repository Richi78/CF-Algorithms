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
    int n; cin >> n;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a), [&](auto x, auto y){return x.size()<y.size();});
    for(int i=1 ; i<n ; i++){
        string before=a[i-1];
        int sz=before.size();
        bool ok=false;
        for(int j=0 ; j+sz<=a[i].size() ; j++){
            string tmp=a[i].substr(j,sz);
            if(before == tmp){
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
    for(auto x : a) cout<< x <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}