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

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
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
    int n,e; cin >> n >> e;
    vector< vector<int> > edges(e);
    for(int i=0 ; i<e ; i++){
        int u,v,w; cin >> u >> v >> w;
        vector<int> tmp={w,u,v};
        edges[i]=tmp;
    }
    //ordenas de menor a mayor
    sort(all(edges), [](auto &x, auto &y){return x[0] < y[0];});
    for(auto x : edges){
        vdebug(x)
    }

    DisjointSet dsu(n);
    vector< vector<int> > mst;
    int mn=0;
    for(auto edge : edges){
        int w=edge[0] , u=edge[1] , v=edge[2];
        if(dsu.findUPar(u) != dsu.findUPar(v)){
            dsu.unionBySize(u,v);
            mn+=w;
            mst.push_back(edge);
        }
    }

    debug1(mn)
    for(auto x: mst){
        vdebug(x)
    }
}

signed main(){
    FIO;
    solve();
}

