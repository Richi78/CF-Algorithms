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
    int n,m,q; cin >> n >> m >> q;
    
    vector< vector<int> > adj(n+1,vector<int>(n+1,4e18));
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u][v]= min(adj[u][v],w);
        adj[v][u]= min(adj[v][u],w);
    } 
    for(int i=1 ; i<=n ; i++){
        adj[i][i]=0;
    }

    for(int via=1 ; via<=n ; via++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
            }
        }
    }

    for(int i=0 ; i<q ; i++){
        int a,b; cin >> a >> b;
        int ans=adj[a][b];
        if(ans != 4e18) cout<<ans<<"\n";
        else cout<<"-1\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}