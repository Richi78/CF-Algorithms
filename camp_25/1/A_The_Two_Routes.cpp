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

int bfs(vector<int> adj[], int n){
    int ans=-1;

    set<array<int,2>> q;
    q.insert({0,1});
    vector<int> vis(n+1);
    while(!q.empty()){
        auto it=*q.begin();
        q.erase(q.begin());
        int dist=it[0] , node=it[1];
        vis[node]=1;
        if(node == n) return dist;
        for(auto adjN : adj[node]){
            if(!vis[adjN]){
                q.insert({dist+1,adjN});
            }
        }
    }
    return ans;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> adj2[n+1];
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i!=j){
                int tmp=count(all(adj[i]), j);
                if(tmp == 0){
                    adj2[i].push_back(j);
                }
            }
        }
    }

    int dist1=bfs(adj, n);
    int dist2=bfs(adj2, n);

    if(dist1 == -1 || dist2 == -1){
        cout<<"-1\n";
    }else{
        cout<< max(dist1,dist2) <<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}