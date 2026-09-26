#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;
const int MOD=1e9+7;

void add_self(long long &a, long long b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

void mini(int &a, int b){
    a=min(a,b);
}

void maxi(int &a, int b){
    a=max(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(make_pair(v,w));
    }

    vector<long long> dist(n,INF);
    vector<long long> ways(n,0);
    vector<int> min_flights(n,1e9);
    vector<int> max_flights(n,0);
    dist[0]=0;
    ways[0]=1;
    min_flights[0]=0;
    max_flights[0]=0;

    priority_queue<
        array<long long,2>,
        vector<array<long long,2>>,
        greater<array<long long,2>>
    > q;

    q.push({0,0});
    while(!q.empty()){
        auto [dis,node] = q.top();
        q.pop();
        if(dis > dist[node]) continue;
        for(auto [adjN,w] : adj[node]){
            if(dis+w < dist[adjN]){
                dist[adjN]=dis+w;
                ways[adjN]=ways[node];
                min_flights[adjN]=min_flights[node]+1;
                max_flights[adjN]=max_flights[node]+1;
                q.push({dis+w,adjN});
            }else if(dis+w == dist[adjN]){
                add_self(ways[adjN],ways[node]);
                mini(min_flights[adjN], min_flights[node]+1);
                maxi(max_flights[adjN], max_flights[node]+1);
            }
        }
    }

    cout<< dist[n-1] <<" "<< ways[n-1]<<" "<< min_flights[n-1] <<" "<< max_flights[n-1] <<"\n";

}