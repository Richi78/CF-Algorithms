#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans;
    queue<int> q;
    for(int i=0 ; i<n ; i++) if(indegree[i]==0) q.push(i);
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto adjN : adj[node]){
            if(--indegree[adjN] == 0){
                q.push(adjN);
            }
        }
    }

    if(ans.size() != n){
        cout<< "IMPOSSIBLE\n"; return 0;
    }

    for(auto &x : ans) cout<< x+1 <<" ";
    cout<<"\n";
}