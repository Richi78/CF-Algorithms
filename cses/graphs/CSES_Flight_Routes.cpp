#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m,k; cin >> n >> m >> k;
    vector<pair<int,int>> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(make_pair(v,w));
    }

    vector<vector<long long>> dist(n, vector<long long>(k,INF));
    dist[0][0]=0;
    
    priority_queue<
        array<long long,2>,
        vector<array<long long,2>>, 
        greater<array<long long,2>>
    > q;
    q.push({0,0});
    while(!q.empty()){
        auto [dis,node] = q.top();
        q.pop();
        if(dis > dist[node][k-1]) continue;
        for(auto [adjN,w] : adj[node]){
            if(dis+w < dist[adjN][k-1]){
                dist[adjN][k-1]=dis+w;
                q.push({dis+w,adjN});
                sort(dist[adjN].begin() , dist[adjN].end());
            }
        }
    }
    for(auto x : dist[n-1])
        cout<< x <<" ";
    cout<<"\n";
}