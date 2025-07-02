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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> pref(n) , suf(n);
    pref[0]=a[0]; suf[n-1]=a[n-1];
    for(int i=1 ; i<n ; i++){
        pref[i]=min(pref[i-1],a[i]);
    }
    for(int i=n-2 ; i>=0 ; i--){
        suf[i]=max(suf[i+1],a[i]);
    }

    string ans="";
    for(int i=0 ; i<n ; i++){
        if(a[i] == pref[i] || a[i] == suf[i]) ans.push_back('1');
        else ans.push_back('0');
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}