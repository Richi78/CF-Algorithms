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
vector<vector<int>> adj;

void dfs(int s, vector<bool> &vis, int &mx){
    vis[s]=true;
    mx=max(mx,s);
    for(auto adjN : adj[s]){
        if(!vis[adjN]){
            dfs(adjN, vis, mx);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    // vector<int> adj[n];
    adj=vector<vector<int>>(n);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>> ranges;
    vector<bool> vis(n);
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            int mx=-1;
            dfs(i, vis, mx);
            ranges.emplace_back(i,mx);
        }
    }

    int ans=0;
    // for(auto [x,y] : ranges){
        // debug2(x,y)
    // }
    for(int i=0 ; i<(int)ranges.size() ; i++){
        int mn=ranges[i].F;
        int mx=ranges[i].S;
        while( ((i+1)<ranges.size()) && (ranges[i+1].F < mx) ){
            mx=max(mx,ranges[i+1].S);
            ans++; i++;
        }
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