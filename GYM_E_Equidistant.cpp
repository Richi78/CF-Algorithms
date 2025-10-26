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

vector<int> bfs(int s, int n, vector<int> adj[]){
    vector<int> dist(n, 1e18);
    dist[s]=0;
    queue<array<int,2>> q;
    q.push({s,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it[0] , dis=it[1];
        for(auto adjN : adj[node]){
            if(dis+1 < dist[adjN]){
                dist[adjN]=dis+1;
                q.push({adjN, dist[adjN]});
            }
        }
    }
    return dist;
}

bool dfs(int s, int p, int target, vector<int> adj[], vector<int> &ans){
    if(s == target){
        ans.push_back(target);
        return true;
    }
    for(auto adjN : adj[s]){
        if(adjN != p){
            bool ok=dfs(adjN, s, target, adj, ans);
            if(ok){
                ans.push_back(s); return true;
            }
        }
    }
    return false;
}

bool valid(vector<int> adj[], int node, int n, vector<int> &teams){
    vector<int> dist=bfs(node,n,adj);
    int tmp=dist[teams[0]];
    bool ok=true;
    for(auto team : teams){
        ok&=dist[team]==tmp;
    }
    return ok;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> adj[n];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> teams(m);
    for(int i=0,x ; i<m ; i++) cin >> x, teams[i]=x-1;

    if(m == 1){
        cout<< "YES\n" << teams[0]+1 <<"\n";
        return;
    }

    int first=0;
    {
        // from a team city to farthest other team city
        vector<int> dist=bfs(teams[0], n, adj);
        int mx=-1;
        for(auto team : teams){
            if(uax(mx,dist[team])) first=team;
        }
    }
    int second=0;
    {
        // from first to the farthest node, tree diameter
        vector<int> dist=bfs(first, n, adj);
        int mx=-1;
        for(auto team : teams){
            if(uax(mx,dist[team])) second=team;
        }
    }
    vector<int> path;
    dfs(first,first,second,adj,path);
    // debug2(first, second)
    // vdebug(path)

    if(path.size()&1){
        int sz=path.size();
        if(valid(adj,path[sz/2],n,teams)) cout<< "YES\n"<< path[sz/2]+1 <<"\n"; 
        else cout<<"NO\n";
    }else{
        cout<<"NO\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}