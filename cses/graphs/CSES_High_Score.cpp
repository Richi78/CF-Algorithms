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
    vector<array<int,3>> edges;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,-w});
    }
    
    vector<int> dist(n+1, 1e17);
    dist[1]=0;
    for(int rep=0 ; rep<n-1 ; rep++){
        for(int i=0 ; i<m ; i++){
            int u=edges[i][0] , v=edges[i][1] , w=edges[i][2];
            if(dist[u] != 1e17 && dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    bool loop=false;
    for(int i=0 ; i<m ; i++){
        int u=edges[i][0] , v=edges[i][1] , w=edges[i][2];
        if(dist[u] != 1e17 && dist[u]+w < dist[v]){
            dist[v]=2e17;
            loop=true;
            // break;
        } 
    }
    if(loop){
        for(int rep=0 ; rep<n-1 ; rep++){
            for(int i=0 ; i<m ; i++){
                int u=edges[i][0] , v=edges[i][1] , w=edges[i][2];
                if(dist[u]==2e17) dist[v]=2e17;
            }
        }
    }
    if(dist[n]==2e17) cout<<"-1\n";
    else cout<< -dist[n] <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}