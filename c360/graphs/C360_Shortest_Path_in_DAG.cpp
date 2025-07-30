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

void dfs(int node, vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &st){
    vis[node]=true;
    for(auto [adjN,adjW] : adj[node]){
        if(!vis[adjN]){
            dfs(adjN, adj, vis, st);
        }
    }
    st.push(node);
}

void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
    }

    vector<bool> vis(n);
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> dist(n, 1e9);
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto [adjN,adjW] : adj[node]){
            if(dist[node]+adjW < dist[adjN]){
                dist[adjN]=dist[node]+adjW;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        if(dist[i] == 1e9) cout<< "-1 ";
        else cout<< dist[i] <<" ";
    }
    cout<< "\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}