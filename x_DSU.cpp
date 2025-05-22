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
        // rank.resize(n+1, 0);
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

    // void unionByRank(int u, int v){
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);
    //     if(ulp_u == ulp_v) return;
    //     if(rank[ulp_u] < rank[ulp_v]){
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if(rank[ulp_v] < rank[ulp_u]){
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else{
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }

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
    DisjointSet dsu(7);
    dsu.unionBySize(1,2);
    dsu.unionBySize(2,3);
    dsu.unionBySize(4,5);
    dsu.unionBySize(6,7);
    dsu.unionBySize(5,6);
    if(dsu.findUPar(3) == dsu.findUPar(7)){
        cout<<"Same"<<endl;
    }else cout<<"Not same"<<endl;
    dsu.unionBySize(3,7);
    if(dsu.findUPar(3) == dsu.findUPar(7)){
        cout<<"Same"<<endl;
    }else cout<<"Not same"<<endl;


}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}


