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
    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> c1 , c2 , vis(n,2);
    queue<array<int,2>> q;
    int color=0; // 0->color1     1->color2
    vis[0]=0;
    c1.push_back(1);
    q.push({0,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it[0] , cur=it[1];
        for(auto adjN : adj[node]){
            if(vis[adjN] == 2){
                vis[adjN]=!cur;
                q.push({adjN,!cur});
                if((!cur)==0) c1.push_back(adjN+1);
                else c2.push_back(adjN+1);
            }
        }
    }
    if(c1.size() <= c2.size()){
        cout<< c1.size() <<"\n";
        for(int i=0 ; i<c1.size() ; i++) cout<< c1[i] <<" ";
        cout<<"\n";
    }else{
        cout<< c2.size() <<"\n";
        for(int i=0 ; i<c2.size() ; i++) cout<< c2[i] <<" ";
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}