#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<bool> vis;
vector<int> ans;

bool dfs(int node, int parent, vector<int> adj[]){
    vis[node]=true;
    for(auto adjN : adj[node]){
        if(adjN == parent) continue;
        if(!vis[adjN]){
            bool tmp=dfs(adjN,node,adj);
            if(tmp) {
                ans.push_back(node);
                return true;
            }
        }else{
            ans.push_back(adjN);
            ans.push_back(node);
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<int> adj[n];

    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.resize(n);
    bool cycle;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            cycle = dfs(i,-1,adj);
            if(cycle) break;
        }
    }

    if(!cycle){
        cout<<"IMPOSSIBLE\n";
    }else{
        int k=1;
        for(int i=1 ; i<(int)ans.size() ; i++){
            k++;
            if(ans[i] == ans[0]) break;
        }
        cout<< k <<"\n";
        for(int i=0 ; i<k ; i++){
            cout<< ans[i]+1 <<" ";
        }
    }

}