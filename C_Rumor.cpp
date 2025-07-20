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

void dfs(int s, vector<int> adj[], vector<bool> &vis, int &mn, vector<int> &a){
    vis[s]=1;
    uin(mn, a[s]);
    for(auto adjN : adj[s]){
        if(!vis[adjN]){
            dfs(adjN, adj, vis, mn, a);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n);
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        if(vis[i]) continue;
        int mn=1e10;
        dfs(i , adj , vis , mn, a);
        cnt+=mn;
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}