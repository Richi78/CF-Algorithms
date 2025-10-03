#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define all(v) v.begin(),v.end()

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> freq(n+1);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        freq[x]++;
    }
    int need=0;
    for(int i=0 ; i<k ; i++){
        if(freq[i] == 0) need++;
    }
    int ans=need;
    if(freq[k]>need){
        ans=freq[k];
    }
    cout<< ans <<"\n";
}
signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
    // solve();
}