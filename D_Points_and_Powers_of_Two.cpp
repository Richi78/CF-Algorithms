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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> ans;
    int mx=-1;

    sort(all(a));

    for(int i=0 ; i<n ; i++){
        vector<int> tmp={a[i]};
        for(int j=i+1 ; j<n ; j++){
            bool ok=true;
            for(auto x : tmp){
                if(__builtin_popcount( abs(x-a[j]) ) != 1){
                    ok=false; break;
                }
            }
            if(ok){
                tmp.push_back(a[j]);
            }
        }
        if(uax(mx, (long long)tmp.size() )){
            ans=tmp;
        }
    }
    cout<< mx <<"\n";
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}