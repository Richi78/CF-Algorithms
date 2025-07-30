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

bool bfs(int s, vector<int> adj[], vector<int> &vis){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x : adj[node]){
            if(x == node) continue;
            if(vis[x] != -1 && vis[x] != vis[node]) continue;
            if(vis[x] == vis[node]) return false;
            vis[x]=!vis[node];  
            q.push(x);
        }
    }
    return true;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n,-1);
    for(int i=0 ; i<n ; i++){
        if(vis[i] == -1){
            bool ok=bfs(i , adj, vis);
            if(!ok){
                cout<<"IMPOSSIBLE\n"; return;
            }
        }
    }  

    for(int i=0 ; i<n ; i++){
        cout<< vis[i]+1 <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}