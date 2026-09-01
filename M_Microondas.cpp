#include <bits/stdc++.h>

using namespace std;

const long long INF=1e17;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector<array<long long,3>> adj[n];
    for(int i=0 ; i<m ; i++){
        long long u,v,w,p; cin >> u >> v >> w >> p;
        u--; v--;
        adj[u].push_back({v,w,p});
        adj[v].push_back({u,w,p});
    }

    vector<vector<long long>> dist(n,vector<long long>(k+1,INF));
    for(int i=0 ; i<=k ; i++) dist[0][i] = 0LL;

    // set<array<long long,3>> st;
    // st.insert({0LL, 0LL, 0LL}); // peso actual, node , #premiun
    priority_queue<array<long long,3>, vector<array<long long,3>>, greater<array<long long,3>> > pq;
    pq.push({0LL,0LL,0LL});

    // while(!st.empty()){
    while(!pq.empty()){
        // auto [dis,node,n_premiun] = *st.begin();
        // st.erase(st.begin());
        auto [dis,node,n_premiun] = pq.top();
        pq.pop();

        if(dis != dist[node][n_premiun]) continue;

        for(auto [adjN,w,p] : adj[node]){
            // sin premium
            if(dis+w < dist[adjN][n_premiun]){
                // if(dist[adjN][n_premiun] != INF){
                    // st.erase({dist[adjN][n_premiun],adjN,n_premiun});
                // }

                dist[adjN][n_premiun]=dis+w;
                // st.insert({dist[adjN][n_premiun],adjN,n_premiun});
                pq.push({dist[adjN][n_premiun],adjN,n_premiun});

            }
            // usando un premium
            if(p != -1 && n_premiun < k){
                if(dis+p < dist[adjN][n_premiun+1]){
                    // if(dist[adjN][n_premiun+1] != INF){
                    //     st.erase({dist[adjN][n_premiun+1],adjN,n_premiun+1});
                    // }

                    dist[adjN][n_premiun+1]=dis+p;
                    // st.insert({dist[adjN][n_premiun+1],adjN,n_premiun+1});
                    pq.push({dist[adjN][n_premiun+1],adjN,n_premiun+1});
                }
            }
        }
    }

    long long mn=INF;
    for(int i=0 ; i<=k ; i++) mn=min(mn,dist[n-1][i]);
    cout<< mn <<"\n";
    return 0;
}