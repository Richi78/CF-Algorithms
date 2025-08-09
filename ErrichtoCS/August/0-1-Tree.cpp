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

vector<bool> vis;
vector<vector<int>> sizes;
vector<int> comp;

void dfs(int node, vector<pair<int,int>> adj[], int search, int &sz){
    vis[node]=true;
    comp.push_back(node);
    for(auto [adjN, adjW] : adj[node]){
        if(!vis[adjN] && adjW==search){
            sz++;
            dfs(adjN, adj, search, sz);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--; 
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }    

    int ans=0;
    sizes=vector<vector<int>>(n,vector<int>(2));
    for(int rep=0 ; rep<2 ; rep++){
        vis.clear();
        vis.resize(n);
        for(int i=0 ; i<n ; i++){
            // countint only REP components
            if(!vis[i]){
                comp.clear();
                int sz=1;
                dfs(i,adj,rep,sz);
                for(int node : comp){
                    sizes[node][rep]=sz;
                }
                ans+=sizes[i][rep]*(sizes[i][rep]-1);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        ans+=(sizes[i][0]-1)*(sizes[i][1]-1);
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