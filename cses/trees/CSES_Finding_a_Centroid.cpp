#include <bits/stdc++.h>

using namespace std;

vector<int> sz;
int n;

void dfs(int node, int par, vector<int> adj[]){
    for(auto adjN : adj[node]) if(adjN != par){
        dfs(adjN,node,adj);
        sz[node]+=sz[adjN];
    }
}

int find_centroid(int node, int par, vector<int> adj[]){
    for(int adjN : adj[node]) if(adjN != par){
        if(sz[adjN] > n/2){
            return find_centroid(adjN,node, adj);
        }
    } 
    return node;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sz.resize(n,1);
    dfs(0,-1,adj);

    cout<< find_centroid(0,-1,adj)+1 <<"\n";
}