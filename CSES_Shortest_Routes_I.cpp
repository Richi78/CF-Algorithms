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

    vector<array<int,2>> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    vector<int> dist(n+1, LONG_LONG_MAX);
    set<array<int,2>> st;
    st.insert({0,1});
    dist[1]=0;
    while(!st.empty()){
        auto it=*st.begin();
        int dis=it[0] , node=it[1];
        st.erase(it);
        for(auto x : adj[node]){
            int adjW=x[0] , adjN=x[1];
            if(dis+adjW < dist[adjN]){
                if(dist[adjN] != LONG_LONG_MAX){
                    st.erase({dist[adjN],adjN});
                }
                dist[adjN]=dis+adjW;
                st.insert({dist[adjN],adjN});
            }
        }
    }

    for(int i=1 ; i<=n ; i++){
        cout<< dist[i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}