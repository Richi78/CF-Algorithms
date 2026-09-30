#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++) parent[i]=i;
    }
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int a, int b){
        parent[a]=b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; 
    vector<long long> day(n+1) , cost(n+1);
    for(int i=1 ; i<=n ; i++) cin >> day[i];
    for(int i=1 ; i<=n ; i++) cin >> cost[i];

    int m; cin >> m;
    vector<int> parent(n+1);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        parent[u]=v;
    }

    long long total = 0;

    vector<double> cur_ratio(n+1);
    priority_queue<pair<double,int>> q;
    for(int i=1 ; i<=n ; i++){
        total += day[i] * cost[i];
        cur_ratio[i] = 1.0*cost[i]/day[i];
        q.push(make_pair(cur_ratio[i] , i));
    }

    DSU dsu(n);

    while(!q.empty()){
        auto [ratio , node] = q.top();
        q.pop();

        if(node != dsu.find(node) || cur_ratio[node] != ratio) continue;

        int par = dsu.find(parent[node]);

        total += day[par] * cost[node];
        day[par] += day[node];
        cost[par] += cost[node];
        
        dsu.unite(node, par);
        
        if(par != 0){
            parent[node]=par;
            cur_ratio[par] = 1.0*cost[par]/day[par];
            q.push(make_pair(cur_ratio[par] , par));
        }
    }
    cout<< total <<"\n";
}