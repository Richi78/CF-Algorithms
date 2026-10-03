#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0 ; i<n ; i++) parent[i]=i;
    }
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    bool unite(int a, int b){
        int A=find(a) , B=find(b);
        if(A == B) return false;
        if(size[A] > size[B]){
            parent[B]=A;
            size[A]+=size[B];
        }else{
            parent[A]=B;
            size[B]+=size[A];
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<array<long long,3>> edges;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w; u--; v--;
        edges.push_back({w,u,v});
    }
    sort(edges.begin() , edges.end());
    DSU dsu(n);
    long long sum=0;
    for(auto &[w,u,v] : edges){
        if(dsu.unite(u,v)){
            sum+=w;
        }
    }
    if(dsu.size[dsu.find(0)] != n)
        cout<<"IMPOSSIBLE\n";
    else
        cout<< sum <<"\n";
}