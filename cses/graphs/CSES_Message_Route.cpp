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
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<array<int,2>> q;
    vector<int> vis(n+1);
    vis[1]=1;
    q.push({1,1});
    int mn=-1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dist=it[0] , node=it[1];
        if(node == n){
            mn=dist; break;
        }
        for(auto adjN : adj[node]){
            if(vis[adjN] == 0){
                vis[adjN]=node;
                q.push({dist+1,adjN});
            }
        }
    }
    if(mn == -1) cout<<"IMPOSSIBLE\n";
    else{
        cout<< mn <<"\n";
        vector<int> ans={n};
        int x=n;
        while(vis[x] != 1){
            ans.push_back(vis[x]);
            x=vis[x];
        }
        ans.push_back(1);
        reverse(all(ans));
        for(int i=0 ; i<(int)ans.size() ; i++){
            cout<< ans[i] <<" ";
        }
        cout<< "\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

