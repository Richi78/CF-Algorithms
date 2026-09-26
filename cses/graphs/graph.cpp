#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

void add_self(long long &a, long long b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

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

    vector<int> topo;
    queue<int> q;
    for(int i=0 ; i<n ; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int adjN : adj[node]){
            if(--indegree[adjN] == 0){
                q.push(adjN);
            }
        }
    }

    vector<long long> dp(n);
    dp[0]=1;
    for(auto node : topo){
        for(auto adjN : adj[node]){
            add_self(dp[adjN], dp[node]);
        }
    }
    cout<< dp[n-1] <<"\n";
}