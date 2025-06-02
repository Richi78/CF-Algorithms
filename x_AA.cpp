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

void solve(int n){
    int e; cin >> e;
    vector<int> adj[n];
    for(int i=0 ; i<e ; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n,-1); //0,1
    vis[0]=0;
    queue<array<int,2>> q;
    q.push({0,0}); // node, parent
    while(!q.empty()){
        auto it= q.front();
        int node=it[0] , p=it[1];
        q.pop();
        for(auto x : adj[node]){
            if(vis[x] == vis[node]){ 
                cout<< "NOT BICOLORABLE." <<endl;return;
            }
            if(vis[x] == -1){
                vis[x]=1-vis[node];
                q.push({x,node});
            }
        }
    }
    cout<< "BICOLORABLE." <<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    while(1){
        int n; cin >> n;
        if(n==0)break;
        solve(n);
    }
}