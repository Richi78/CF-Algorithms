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
    vector<int> adj[n];
    vector<int> indegree(n);
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[v].push_back(u);
        indegree[u]++;
    }

    queue<int> q;
    for(int i=0 ; i<n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto adjN : adj[node]){
            if(--indegree[adjN] == 0){
                q.push(adjN);
            }
        }
    }

    cout<< (cnt==n?"Yes\n":"No\n");
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}