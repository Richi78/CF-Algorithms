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
    vector<int> a(26) , b(26);
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        int idx=s[0]-'a';
        if(a[idx] == b[idx]){
            a[idx]++;
        }else if(a[idx] > b[idx]){
            b[idx]++;
        }
    }

    int ans=0;
    for(int i=0 ; i<26 ; i++){
        if(a[i] >= 2) ans+=a[i]*(a[i]-1)/2;
        if(b[i] >= 2) ans+=b[i]*(b[i]-1)/2;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

