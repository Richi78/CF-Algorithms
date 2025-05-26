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
    int n; cin >> n;
    vector<int> a={-1};
    auto it=a.begin();
    for(int i=1; i<=n ; i++){
        int x; cin >> x;
        if(x > *it+1){
            a.push_back(x);
            it=--a.end();
        }
    }
    int cnt=0;
    // vdebug(a)
    // for(int i=1 ; i+1<=a.size() ; i++){
        // if(a[i]+1 )
    // }
    cout<<a.size()-1<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

