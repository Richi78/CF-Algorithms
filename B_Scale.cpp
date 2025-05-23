#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    // for(auto x : a){
    //     debug1(x)
    // }

    vector<string> ans;
    for(int i=0 ; i<n ; i+=k){
        string tmp="";
        for(int j=0 ; j<n ; j+=k){
            tmp.push_back(a[i][j]);
        }
        ans.push_back(tmp);
    }
    for(auto x : ans){
        cout<<x<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}