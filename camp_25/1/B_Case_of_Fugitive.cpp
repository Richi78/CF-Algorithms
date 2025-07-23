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
    int n,m; cin >> n >> m;
    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        int u,v; cin >> u >> v;
        a.emplace_back(u,v);
    }

    vector<pair<int,int>> bridges;
    for(int i=1 ; i<=m ; i++){
        int x; cin >> x;
        bridges.emplace_back(x,i);
    }

    vector<pair<int,int>> dist;
    for(int i=1 ; i<n ; i++){
        int mn=a[i].F-a[i-1].S;
        int mx=a[i].S-a[i-1].F;
        dist.emplace_back(mn,mx);
    }

    sort(all(bridges), [&](auto x, auto y){return x.F>y.F;});
    sort(all(dist) , [&](auto x, auto y){return x.S>y.S;});

    vector<pair<int,int>> ans;
    int i=0; // ptr dist
    int j=0; // ptr bridges
    while(i<n-1 && j<m){
        int mn=dist[i].F , mx=dist[i].S;
        int dis=bridges[j].F;
        if(dis>=mn && dis<=mx){
            ans.push_back(bridges[j]);
            i++; j++;
        }else{
            j++;
        }
    }
    
    if(ans.size() == n-1){
        cout<< "Yes\n";
        for(auto [x,y] : ans){
            cout<< y <<" ";
        }
        cout<<"\n";
    }else{
        cout<< "No\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}