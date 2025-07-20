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

vector<int> topsort;

void dfs(int s, vector<int> adj[], vector<int> &vis){
    vis[s]=1;
    for(auto node : adj[s]){
        if(vis[node] == 0){
            dfs(node, adj, vis);
        }
    }
    topsort.push_back(s);
}

void solve(){
    int n,m; cin >> n >> m;
    
    vector<int> adj[n+1];
    vector<int> indegree(n+1);

    for(int i=0 ; i<m ; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    // vector<int> vis(n+1);
    // for(int i=0 ; i<n ; i++){
    //     if(vis[i] == 0){
    //         dfs(i, adj, vis);
    //     }
    // }

    // reverse(all(topsort));

    set<int> q;
    for(int i=1 ; i<=n ; i++){
        if(indegree[i] == 0) q.insert(i);
    }

    while(!q.empty()){
        int node=*q.begin();
        q.erase(q.begin());
        topsort.push_back(node);
        for(auto adjN : adj[node]){
            indegree[adjN]--;
            if(indegree[adjN] == 0) q.insert(adjN);
        }
    }
    
    if(topsort.size() != n){
        cout<< "Sandro fails.\n"; return;
    }
    for(auto x : topsort){
        cout<< x <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}