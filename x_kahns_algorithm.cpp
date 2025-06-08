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

vector<int> kahn(int n, vector<int> adj[], vector<int> indegree){
    vector<int> ans;
    queue<int> q;
    for(int i=0 ; i<n ; i++){
        int x=indegree[i];
        if(x == 0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto x : adj[node]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> adj[n] , indegree(n);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans=kahn(n , adj, indegree);

    vdebug(ans)
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}