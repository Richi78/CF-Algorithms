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

void dfs(int node, int parent, vector<int> adj[], vector<int> &tin,
    vector<int> &low, vector<bool> &artPoint, int &t){
    tin[node]=low[node]=++t;
    int child=0;
    for(auto adjN : adj[node]){
        if(adjN == parent) continue;
        if(!tin[adjN]){
            dfs(adjN, node, adj, tin, low, artPoint, t);
            low[node]=min(low[node],low[adjN]);
            if(low[adjN] >= tin[node] && parent != -1){
                artPoint[node]=true;
            }
            child++;
        }else{
            low[node]=min(low[node],tin[adjN]);
        }
    }
    if(child>1 && parent==-1) artPoint[node]=true;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n+1) , low(n+1);
    vector<bool> artPoint(n+1);
    int t=0;
    for(int i=1 ; i<=n ; i++){
        if(tin[i] == 0){
            dfs(i , -1 , adj , tin , low , artPoint, t);
        }
    }
    for(int i=1; i<=n ; i++){
        if(artPoint[i]) cout<< i <<" ";
    }
    cout<<"\n";   
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}