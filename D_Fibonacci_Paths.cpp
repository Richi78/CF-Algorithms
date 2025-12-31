#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD=998244353;
int ans=0;
vector<int> val,dp;
vector<bool> path,vis;
map<pair<int,int>,bool> mp;

void dfs(int node, vector<int> adj[], int par){
    path[node]=true;
    for(auto adjN : adj[node]){
        if(path[adjN] || mp[make_pair(node,adjN)]) continue;
        // dp[adjN]=(dp[adjN] + 1)%MOD;
        // ans=(ans+dp[adjN])%MOD;
        mp[make_pair(node,adjN)]=true;
        ans=(ans+1)%MOD;
        // debug1(ans)
        if(par != -1 && (val[par]+val[node])==val[adjN]){
            // dp[adjN]=(dp[adjN] + 1)%MOD;
            // ans=(ans+dp[adjN])%MOD;
            ans=(ans+1)%MOD;
            // debug1(ans)
        }
        dfs(adjN,adj,node);
    }
    path[node]=false;
}

void solve(){
    int n,m; cin >> n >> m;
    val.resize(n); 
    for(int i=0 ; i<n ; i++) cin >> val[i];
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }    

    path.resize(n); vis.resize(n); dp.resize(n);
    for(int i=0 ; i<n ; i++){
        if(!vis[i]) vis[i]=true , dfs(i,adj,-1);
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