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

// int mn=1e9;
// vector<int> t;
// int cnt=1;

// void dfs(int s, int parent, vector<int> adj[], vector<int> &vis){
//     t[s]=cnt; cnt++;
//     vis[s]=1;
//     bool skip=true;
//     for(auto adjN : adj[s]){
//         if(vis[adjN] == -1){
//             dfs(adjN, s, adj, vis);
//         }else{
//             if(adjN==parent && skip){
//                 skip=false;
//                 continue;
//             }
//             int edges=t[s]-t[adjN];
//             uin(mn,edges+1);
//             debug2(edges, mn)
//         }
//     }
// }
int n;
int ans=1e9;

void bfs(int s, vector<int> adj[]){
    vector<int> vis(n,-1);
    vis[s]=0;
    queue<array<int,3>> q;
    q.push({0,s,-1});
    while(!q.empty()){
        auto it=q.front();
        int dist=it[0] , node=it[1] , parent=it[2];
        q.pop();
        for(auto adjN : adj[node]){
            if(vis[adjN] == -1){
                vis[adjN]=dist+1;
                q.push({vis[adjN],adjN,node});
            }else{
                if(adjN==parent){
                    continue;
                }
                uin( ans, dist+1+vis[adjN]);
            }
        }
    } 
}

void solve(){
    int m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0 ; i<n ; i++){
        bfs(i, adj);
    }

    cout<< (ans==1e9?-1:ans) <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}