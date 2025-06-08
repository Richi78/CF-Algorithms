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

void dfs(vector<int> adj[], int s, stack<int> &st, vector<int> &vis){
    vis[s]=1;
    for(auto x : adj[s]){
        if(vis[x] == 0){
            dfs(adj, x, st, vis);
        }
    }
    st.push(s);
}

vector<int> toposort(int n, vector<int> adj[]){
    vector<int> vis(n);
    stack<int> st;

    for(int i=0 ; i<n ; i++){
        if(vis[i] == 0){
            dfs(adj, i, st, vis);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> tsort=toposort(n,adj);
    vdebug(tsort) 
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}