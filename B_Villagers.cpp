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
    map<int,int> freq;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        freq[x]++;
    }
    int ans=0;
    vector<int> a;
    for(auto [x,y] : freq){
        if(y&1){
            a.push_back(x);
        }
        ans+=x*(y/2);
    }
    sort(all(a));
    int sz=(int)a.size();
    if(sz&1){
        for(int i=sz-1 ; i>=1 ; i-=2){
            ans+=a[i];
        }
        ans+=a[0];
    }else{
        for(int i=1 ; i<sz ; i+=2){
            ans+=a[i];
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