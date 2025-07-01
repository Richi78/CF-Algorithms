#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve(){
    int n,m,k; cin >> n >> m >> k;

    vector< array<int,2> > adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    // DisjointSet dsu(n);
    // vector<int> dist(n+1,4e18);
    // set<array<int,2>> st;
    // st.insert({0,1});
    // dist[1]=0;
    queue<array<int,3>> q;
    q.push({0,1,1});
    vector<int> ans;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dis=it[0] , node=it[1] , parent=it[2];
        if(node == n){
            ans.push_back(dis); continue;
        }
        for(auto x : adj[node]){
            int adjW=x[0] , adjN=x[1];
            if(adjN != parent){
                q.push({dis+adjW,adjN,node});
            }
        }
    }

    sort(all(ans));

    for(int i=0 ; i<k ; i++){
        cout<< ans[i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}