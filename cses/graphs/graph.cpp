#include <bits/stdc++.h>

using namespace std;

stack<int> st;
vector<bool> vis;
vector<int> a;
int scc_component=0;

void dfs1(int node, vector<int> adj[]){
    vis[node]=true;
    for(auto adjN : adj[node]) if(!vis[adjN]) dfs1(adjN,adj);
    st.push(node);
}

void dfs2(int node, vector<int> adj[]){
    vis[node]=true;
    a[node]=scc_component;
    for(auto adjN : adj[node]) if(!vis[adjN]) dfs2(adjN,adj);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
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

    a.resize(n);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc_component++;
            dfs2(node, adjT);
        }
    }
    cout<< scc_component <<"\n";
    for(auto &x : a) cout<< x <<" ";
    cout<<"\n";
}