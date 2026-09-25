#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1,w));
    }

    vector<vector<long long>> dist(n,vector<long long>(2,INF));
    dist[0][0]=0;
    priority_queue<array<long long,3>, vector<array<long long,3>>, greater<array<long long,3>> > q;
    //dist, node, state
    q.push({0,0,0});
    while(!q.empty()){
        auto [dis,node,state] = q.top();
        q.pop();
        if(dis > dist[node][state]) continue;
        for(auto [adjN,w] : adj[node]){
            if(dis+w < dist[adjN][state]){ // no take, do the same
                dist[adjN][state]=dis+w;
                q.push({dis+w,adjN,state});
            }
            // take, check if not taken yet and take
            if(state == 0 && dis+w/2 < dist[adjN][1]){
                dist[adjN][1]=dis+w/2;
                q.push({dis+w/2,adjN,1});
            }
        }
    }
    cout<< dist[n-1][1] <<"\n";
}