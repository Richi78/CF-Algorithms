#include <bits/stdc++.h>

using namespace std;

#define int long long

// priority queue
vector<int> dijkstra(int n, vector<vector<int>> adj[], int s){
    priority_queue<
        pair<int,int>,
        vector< pair<int,int> >,
        greater< pair<int,int> > 
    > pq;   // min heap

    vector<int> dist(n,1e9);

    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push( {dist[adjNode] , adjNode});
            }
        }
    }
    return dist;
}

// set
vector<int> dijkstra(int n, vector<vector<int>> adj[], int s){
    set< pair<int,int> > st;
    vector<int> dist(n,1e9);

    dist[s] = 0;
    st.insert({0,s});

    while(!st.empty()){
        auto it=*st.begin();
        int dis = it.first;
        int node = it.second;
        st.erase(it); 
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dis + edgeWeight < dist[adjNode]){
                // erase if existed
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode] , adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode] , adjNode}); 
            }
        }
    }
    return dist;
}

signed main(){

}