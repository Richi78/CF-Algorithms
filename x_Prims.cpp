#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

// si no te dan la lista de adj hacer prims es costoso
int prims(int n, map<int, vector<pair<int,int>> > &adj){
    vector< array<int,3> > mst;
    int mn=0;
    vector<int> vis(n+1);

    priority_queue<
        array<int,3>, 
        vector< array<int,3> >,
        greater< array<int,3> >
    > pq; // {w,{u,v}}

    pq.push({0, adj.begin()->F ,adj.begin()->F}); // el primer nodo no cuesta nada
            //w,n,p
    while( !pq.empty() ){
        auto a=pq.top();
        pq.pop();
        int node=a[1] , parent=a[2] , w=a[0];

        if(vis[node]) continue;
        vis[node]=1;
        mst.push_back(a);
        mn+=w;
        for(auto it : adj[node]){
            int adjN=it.F , adjW=it.S;
            if(!vis[adjN]) pq.push({adjW, adjN, node});
        }
    }
    return mn;
}

void solve(){
    int n,e; cin >> n >> e;

    map<int, vector<pair<int,int>>> adj; // v,w
    
    for(int i=0 ; i<e ; i++){
        int u,v,w; cin >> u >> v >>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int ans=prims(n, adj);
    
    // for(auto x : mst){
        // vdebug(x)
    // }
    cout<< ans <<endl;
}

signed main(){
    FIO;
    solve(); 
}


