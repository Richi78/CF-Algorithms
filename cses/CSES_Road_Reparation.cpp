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

    bool unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            return true;
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            return true;
        }
    }
};

void solve(){
    int n,m; cin >> n >> m;

    vector<array<int,3>> edges;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }
    
    sort(all(edges));

    DisjointSet dsu(n);
    int sum=0;
    vector<array<int,3>> mst;
    for(int i=0 ; i<m ; i++){
        int u=edges[i][1] , v=edges[i][2] , w=edges[i][0];
        if(dsu.unionBySize(u,v)){
            sum+=w; mst.push_back(edges[i]);
        } 
    }

    if(mst.size() == n-1) cout<< sum <<"\n";
    else cout<< "IMPOSSIBLE\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}