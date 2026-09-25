#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<array<int,3>> edges(m);
    vector<long long> dist(n,-INF);
    dist[0]=0;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        edges[i]={u-1,v-1,w};
    }

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<m ; j++){
            auto [u,v,w] = edges[j];
            if(dist[u] == -INF) continue;
            if(dist[u]+w > dist[v])
                dist[v]=dist[u]+w;
        }
    }

    bool cycle=false;
    for(int j=0 ; j<m ; j++){
        auto [u,v,w] = edges[j];
        if(dist[u] == -INF) continue;
        if(dist[u]+w > dist[v]){
            cycle=true;
            dist[v]=-INF*2;
        }
    }

    for(int i=0 ; i<n-1 && cycle ; i++){
        for(int j=0 ; j<m ; j++){
            auto [u,v,w] = edges[j];
            if(dist[u] == -INF*2) dist[v]=-INF*2;
        }
    }

    cout<< (dist[n-1]==(-INF*2) ? -1 : dist[n-1]) <<'\n';
}