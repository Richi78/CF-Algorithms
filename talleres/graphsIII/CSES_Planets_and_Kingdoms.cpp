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

void dfs(int s, vector<int> adj[], vector<int> &vis,stack<int> &st){
    vis[s]=1;
    for(auto adjN : adj[s]){
        if(!vis[adjN]){
            dfs(adjN , adj , vis , st);
        }
    }
    st.push(s);
}

void dfs2(int s, vector<int> adj[], vector<int> &vis, vector<int> &scc, int scc_number){
    vis[s]=1;
    scc[s]=scc_number;
    for(auto adjN : adj[s]){
        if(!vis[adjN]){
            dfs2(adjN , adj , vis , scc , scc_number);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;

    vector<int> adj[n];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n);
    stack<int> st;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    
    vector<int> adjT[n];
    for(int i=0 ; i<n ; i++){
        vis[i]=0;
        for(auto adjN : adj[i]){
            adjT[adjN].push_back(i);
        }
    }
    
    vector<int> scc(n);
    int scc_number=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc_number++;
            dfs2(node, adjT, vis, scc, scc_number);
        }
    }

    cout<< scc_number <<"\n";
    for(int i=0 ; i<n ; i++){
        cout<< scc[i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}