#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

vector<int> ans;
vector<int> a;

void dfs(int node, int par, vector<int> adj[], int sum, int x, int y){
    sum=a[node]-sum;
    ans[node]=sum+x;
    for(auto adjN : adj[node]){
        if(adjN != par){
            dfs(adjN,node,adj,sum,max(y,sum),x);
        }
    }
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    vector<int> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    ans.resize(n);
    dfs(0,-1,adj,0,0,0);
    for(auto x : ans) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}