#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<int> parent;

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

    vector<int> topsort;
    queue<int> q;
    for(int i=0 ; i<n ; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        topsort.push_back(node);
        for(auto adjN : adj[node]){
            if(--indegree[adjN] == 0){
                q.push(adjN);
            }
        }
    }

    dp.resize(n,-1);
    parent.resize(n,-1);
    dp[0]=0;

    for(auto node : topsort){
        if(dp[node] == -1) continue;
        for(auto adjN : adj[node]){
            if(dp[node]+1 > dp[adjN]){
                dp[adjN]=dp[node]+1;
                parent[adjN]=node;
            }
        }
    }
    
    if(dp[n-1] == -1){
        cout<< "IMPOSSIBLE\n"; return 0;
    }

    vector<int> ans;
    for(int cur=n-1 ; cur!=-1 ; cur=parent[cur]) ans.push_back(cur);
    reverse(ans.begin() , ans.end());
    cout<< ans.size() <<"\n";
    for(auto &x : ans) cout<< x+1 <<" ";
    cout<<"\n";
}