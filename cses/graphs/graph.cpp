#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> a;
stack<int> st;
vector<bool> vis;
vector<int> scc;
int component_number=-1;

void dfs1(int node, vector<int> adj[]){
    vis[node]=true;
    for(auto adjN : adj[node]) if(!vis[adjN]) dfs1(adjN,adj);
    st.push(node);
}

void dfs2(int node, vector<int> adj[]){
    vis[node]=true;
    scc[node]=component_number;
    for(auto adjN : adj[node]) if(!vis[adjN]) dfs2(adjN,adj);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    a.resize(n);
    for(auto &x :a) cin >> x;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }

    vis.resize(n);
    for(int i=0 ; i<n ; i++) if(!vis[i]) dfs1(i,adj);

    vector<int> adjT[n];
    for(int i=0 ; i<n ; i++){
        vis[i]=false;
        for(auto adjN : adj[i]) adjT[adjN].push_back(i);
    }

    scc.resize(n);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            component_number++;
            dfs2(node,adjT);
        }
    }

    vector<int> new_a(component_number+1);
    for(int i=0 ; i<n ; i++) new_a[scc[i]]+=a[i];

    vector<vector<int>> scc_graph(component_number+1);
    for(int i=0 ; i<n ; i++) for(auto adjN : adj[i]) if(scc[i] != scc[adjN]){
        scc_graph[scc[i]].push_back(scc[adjN]);
    }

    vector<int> dp=new_a;
    for(int i=0 ; i<=component_number ; i++) for(auto adjN : scc_graph[i]){
        dp[adjN] = max(dp[adjN], dp[i] + new_a[adjN]);
    }
    int mx=0;
    for(auto &x : dp) mx=max(mx,x);
    cout<< mx <<"\n";
}