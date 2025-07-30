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
    int n,m,k; cin >> n >> m >> k;

    vector< array<int,2> > adj[n+1];
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    vector< vector<int> > dist(n+1, vector<int>(k,1e18));
    dist[1][0]=0;
    multiset<array<int,2>> st;
    st.insert({0,1});

    while(!st.empty()){
        auto it=*st.begin();
        int dis=it[0] , node=it[1];
        st.erase(st.begin());
        if(dist[node][k-1] < dis) continue;
        for(auto x : adj[node]){
            int adjW=x[0] , adjN=x[1];
            if(dis+adjW < dist[adjN][k-1]){
                dist[adjN][k-1]=dis+adjW;
                st.insert({dist[adjN][k-1],adjN});
                sort(all(dist[adjN]));
            }
        }
    }

    for(int i=0 ; i<k ; i++){
        cout<< dist[n][i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}