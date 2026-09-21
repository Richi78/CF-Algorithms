#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<int> dist(n,INF);
    vector<int> parent(n);
    dist[0]=0; parent[0]=-1;

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto [node, dis] = q.front(); q.pop();
        for(auto adjN : adj[node]){
            if(dis+1 < dist[adjN]){
                dist[adjN]=dis+1;
                parent[adjN]=node;
                q.push(make_pair(adjN, dis+1));
            }
        }
    }

    if(dist[n-1] == INF){
        cout<< "IMPOSSIBLE\n"; return 0;
    }

    int cur=n-1;
    vector<int> path;

    while(cur != -1){
        path.push_back(cur+1);
        cur=parent[cur];
    }

    reverse(path.begin() , path.end());
    cout<< path.size() <<"\n";
    for(auto &e : path) cout<< e <<" "; cout<<"\n";
}