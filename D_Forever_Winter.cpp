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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }

    int node_x , node_y;
    for(int i=1 ; i<n ; i++){
        if(indegree[i] == 1){
            node_y=adj[i].back(); 
            break;
        }
    }
    int y=indegree[node_y];
    for(auto x : adj[node_y]){
        if(indegree[x]!= 1){
            node_x=x;
            break;
        }
    }
    int x=indegree[node_x];
    cout<< x <<" "<< y-1<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}