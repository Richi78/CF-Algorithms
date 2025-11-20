#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int INF=1e18;

pair<int,int> bfs(int node, vector<int> adj[], int n){
    vector<int> dist(n,INF);
    dist[node]=0;
    int ans=-1;
    int mx=0;
    queue<array<int,2>> q;
    q.push({node,0});
    while(!q.empty()){
        auto [cur,dis]=q.front();
        q.pop();
        for(auto adjN : adj[cur]){
            if(dis+1<dist[adjN]){
                dist[adjN]=dis+1;
                if(uax(mx,dist[adjN])) ans=adjN;
                q.push({adjN,dist[adjN]});
            }
        }
    }
    return make_pair(ans,mx);
}

void solve(){
    int n; cin >> n;
    vector<int> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n == 1){
        cout<<"0\n"; return;
    }

    pair<int,int> node=bfs(0,adj,n);
    pair<int,int> ans=bfs(node.first,adj,n);
    cout<< ans.second <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}