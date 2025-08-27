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

#define F first
#define S second

void solve(){
    int n; cin >> n;
    vector<array<int,3>> a(n);
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a[i]={x,y,i+1};
    }
    
    vector<pair<int,int>> ans;
    
    for(int rep=0 ; rep<2 ; rep++){
        sort(all(a), [&](auto x, auto y){return x[1]>y[1];});
        vector<pair<int,int>> tmp;
        for(int i=0 ; i<n ; i++){
            if(a[i][1] > a[i][0] && (tmp.empty() || a[tmp.back().F][1]>a[i][0])){
                tmp.emplace_back(i,a[i][2]);
            }    
        }
        if(tmp.size() > ans.size()) ans=tmp;
        for(int i=0 ; i<n ; i++) a[i][0]*=-1 , a[i][1]*=-1;
    }

    // ans=tmp;
    // tmp.clear();
    // sort(all(a), [&](auto x, auto y){return x[1]<y[1];});
    // for(int i=0 ; i<n ; i++){
        // if(a[i][1] < a[i][0] && (tmp.empty() || a[tmp.back().F][1]<a[i][0])){
            // tmp.emplace_back(i,a[i][2]);
        // }
    // }

    // if(ans.size() < tmp.size()) ans=tmp;
    cout<< ans.size() <<"\n";
    for(auto [x,y] : ans) cout<< y <<" ";
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