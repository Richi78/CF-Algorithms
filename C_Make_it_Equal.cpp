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

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    multiset<int> b;

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        b.insert(x%k);
    }

    vector<pair<int,int>> ans(n);
    for(int i=0 ; i<n ; i++){
        ans[i].F=a[i]%k;
        ans[i].S=abs(a[i]%k-k)%k;
    }

    for(int i=0 ; i<n ; i++){
        auto it=b.find(ans[i].F);
        if(it != b.end()){
            b.erase(it);
            continue;
        }
        auto it2=b.find(ans[i].S);
        if(it2 != b.end()){
            b.erase(it2);
            continue;
        }
        cout<< "NO\n"; return;
    }
    cout<< "YES\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}