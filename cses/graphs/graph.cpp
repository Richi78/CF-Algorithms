#include <bits/stdc++.h>

using namespace std;

class DSU{
    public:
    vector<int> parent,size;
    int groups;
    DSU(int n){
        parent.resize(n); size.resize(n); groups=n;
        for(int i=0 ; i<n ; i++) parent[i]=i , size[i]=1;
    }
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    int unionFind(int a, int b){
        int A=find(a) , B=find(b);
        if(A == B) return -1;
        groups--;
        if(size[A] > size[B]){
            parent[B]=A; size[A]+=size[B]; 
            return A;
        }else{
            parent[A]=B; size[B]+=size[A];
            return B;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;

    DSU dsu(n);

    for(int rep=0 ; rep<m ; rep++){
        int u,v; cin >> u >> v; u--; v--;
        dsu.unionFind(u,v);
    }

    if(dsu.groups == 1){ cout<< "0\n"; return 0;}

    vector<pair<int,int>> ans;

    int tmp=dsu.find(0);
    for(int i=1 ; i<n ; i++){
        int x=dsu.find(i);
        if(tmp != x){
            dsu.unionFind(0,i); tmp=dsu.find(0);
            ans.push_back(make_pair(0,i));
        }
    }

    assert(dsu.groups == 1);

    cout<< ans.size() <<"\n";
    for(auto &[x,y] : ans) cout<< x+1 << " " << y+1 <<"\n";
}