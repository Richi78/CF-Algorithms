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

void solve(){
    int n,m,k; cin >> n >> m >> k;
    map<int,vector<int>> mp;
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        mp[x].push_back(i);
    }

    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int INF=1e18;
    vector<int> dist(n+1,INF);
    dist[1]=0;
    queue<array<int,2>> q;
    q.push({1,0});
    while(!q.empty()){
        auto [node,dis]=q.front();
        q.pop();
        for(auto adjN : adj[node]){
            if(dis+1 < dist[adjN]){
                dist[adjN]=dis+1;
                q.push({adjN,dist[adjN]});
            }
        }
    }

    vector<int> ans(k+1);
    for(auto [x,y] : mp){
        int mx=0;
        for(int i=0 ; i<y.size() ; i++){
            uax(mx,dist[y[i]]);
        }
        ans[x]=mx;
    }
    for(int i=1 ; i<=k ; i++) cout << ans[i] <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}