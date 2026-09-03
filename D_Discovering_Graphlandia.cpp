#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int idx = min_element(a.begin(), a.end()) - a.begin();
    vector<int> ans(n,1);
    
    queue<int> q;
    q.push(idx);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto adjN : adj[node]){
            if(a[adjN] >= a[node]){
                ans[adjN]+=ans[node];
                q.push(adjN);
            }
        }
    }
    for(auto &x : ans) cout<< x <<"\n";
    
    return 0;
}