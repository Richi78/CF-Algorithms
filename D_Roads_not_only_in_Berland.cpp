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
    public:
    vector<int> parent,size;
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
    int n; cin >> n;
    
    DisjointSet dsu(n);

    vector<pair<int,int>> a;
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        if(!dsu.unionBySize(u,v)){
            a.emplace_back(u,v);
        }
    }

    if(a.size() == 0){
        cout<<"0\n";
        return;
    }

    set<int> remaining(dsu.parent.begin()+1 , dsu.parent.end());
    
    cout<< a.size() <<"\n";
    for(auto [x,y] : a){
        // debug2(x,y)
        for(auto z : remaining){
            if(dsu.unionBySize(x,z)){
                cout<< x <<" "<< y <<" "<< x <<" "<< z <<"\n";
                remaining.erase(z);
                break;
            }
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}