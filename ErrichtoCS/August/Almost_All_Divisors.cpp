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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    sort(all(a));

    int ans=a[0]*a[n-1];
    vector<int> b;
    for(int i=2 ; i*i<=ans ; i++){
        if(ans%i == 0){
            b.push_back(i);
            if(ans/i != i){
                b.push_back(ans/i);
            }
        }
    }

    sort(all(b));
    if(a.size() != b.size()){
        cout<<"-1\n"; return;
    }
    for(int i=0 ; i<n ; i++){
        if(a[i] != b[i]){
            cout<<"-1\n"; return;
        }
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