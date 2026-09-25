#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<bool> path;
vector<int> cycle;

bool dfs(int node, vector<int> adj[]){
    vis[node]=true;
    path[node]=true;
    for(auto adjN : adj[node]){
        if(adjN == node) continue;
        if(!vis[adjN]){
            bool tmp=dfs(adjN,adj);
            if(tmp){
                cycle.push_back(node);
                return true;
            }
        }else if(path[adjN]){
            cycle.push_back(adjN);
            cycle.push_back(node);
            return true;
        }
    } 
    path[node]=false;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vis.resize(n);
    path.resize(n);

    bool tmp=false;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            tmp=dfs(i,adj); 
            if(tmp) break;
        }
    }

    if(!tmp){
        cout<<"IMPOSSIBLE\n"; return 0;
    }

    vector<int> ans;
    for(auto &x : cycle){
        ans.push_back(x);
        if(ans[0]==x && ans.size()>1) break;
    }
    reverse(ans.begin(), ans.end());

    cout<< ans.size() <<"\n";
    for(auto &x : ans) cout<< x+1 <<" ";
    cout<<"\n";

}