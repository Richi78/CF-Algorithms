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

void solve(){
    int n,m; cin >> n >> m;
    
    vector< array<int,3> > edges;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    vector<int> dist(n, 1e9);
    dist[0]=0;
    for(int i=0 ; i<n-1 ; i++){
        for(auto x : edges){
            int u=x[0] , v=x[1] , w=x[2];
            if(dist[u] != 1e9 && dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(auto x : edges){
        int u=x[0] , v=x[1] , w=x[2];
        if(dist[u] != 1e9 && dist[u]+w < dist[v]){
            cout<< "possible\n"; return;
        }
    }
    cout<< "not possible\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}