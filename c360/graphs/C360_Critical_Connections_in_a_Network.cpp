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

void dfs(int node, int parent, vector<int> adj[], vector<int> &time,
        vector<int> &low, vector<array<int,2>> &ans, int &t){
    time[node] = low[node] = t;
    t++;
    for(auto adjN : adj[node]){
        if(adjN == parent) continue;
        if(!time[adjN]){
            dfs(adjN, node, adj, time, low, ans, t);
            low[node]=min(low[node],low[adjN]);
            if(time[node] < low[adjN]){
                int mn=min(node,adjN) , mx=max(node,adjN);
                ans.push_back({mn,mx});
            }
        }else{
            low[node]=min(low[node],low[adjN]);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> time(n+1) , low(n+1);
    vector<array<int,2>> ans;
    int t=1;
    dfs(1, -1, adj, time, low, ans, t);
    sort(all(ans));
    for(auto [x,y] : ans){
        cout<< x <<" "<< y <<"\n";
    }
    if(ans.empty()) cout<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}