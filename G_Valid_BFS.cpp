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
    int n; cin >> n;
    vector<int> adj[n+1];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]=x;
    } 

    // vector<bool> vis(n);
    // map<int,vector<int>> g;
    // queue<pair<int,int>> q;
    // q.push({1,0});
    // while(!q.empty()){
    //     auto [level,node] = q.front();
    //     q.pop();
    //     vis[node]=1;
    //     g[level].push_back(node);
    //     for(auto adjN : adj[node]){
    //         if(vis[adjN]) continue;
    //         q.push({level+1,adjN});
    //     }
    // }

    // int idx=0;
    // for(auto x : g){
    //     sort(a.begin()+idx , a.begin()+idx+x.S.size());
    //     sort(all(x.S));
    //     // vdebug(a)
    //     // vdebug(x.S)
    //     bool ok=true;
    //     for(int i=0 ; i< x.S.size() ; i++){
    //         if(a[i+idx] != x.S[i]){
    //             ok=false; break;
    //         }
    //     } 
    //     if(!ok){
    //         cout<<"No\n"; return;
    //     }
    //     idx+=x.S.size();
    // }
    // cout<<"Yes\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}