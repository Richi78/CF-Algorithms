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
    int n,m; cin >> n >> m;
    
    vector<vector<int>> a(n);
    vector<int> freq(m+1);
    for(int i=0 ; i<n ; i++){
        int l; cin >> l;
        vector<int> tmp(l);
        for(int j=0 ; j<l ; j++){
            cin >> tmp[j];
            freq[tmp[j]]++;
        }
        a[i]=tmp;
    }
    int cnt=0;
    for(int i=1 ; i<=m ; i++){
        if(freq[i] == 0){
            cout<<"NO\n"; return;
        }   
        cnt=max(cnt,freq[i]);
    }
    if(cnt>=3) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}