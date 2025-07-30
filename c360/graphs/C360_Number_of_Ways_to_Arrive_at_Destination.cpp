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

const int MOD=1e9+7;

void solve(){
    int n; cin >> n;
    vector<pair<long long,long long>> adj[n];
    for(int i=0 ; i<10 ; i++){ // poner el (int)roads.size()
        int u,v,w; cin >> u >> v >> w;
        // int u=roads[i][0] , v=roads[i][1] , w=roads[i][2]; 
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    set<array<long long,2>> st;
    st.insert({0,0});
    vector<long long> dist(n,1e17) , ways(n);
    dist[0]=0;
    ways[0]=1;
    while(!st.empty()){
        auto it=*st.begin();
        st.erase(st.begin());
        long long dis=it[0] , node=it[1];
        for(auto [adjN,adjW] : adj[node]){
            long long tmp=dis+adjW;
            if(tmp < dist[adjN]){
                if(dist[adjN] != 1e17){
                    st.erase({dist[adjN],adjN});
                }
                dist[adjN]=tmp;
                ways[adjN]=ways[node];
                st.insert({dist[adjN],adjN});
            }else if(tmp == dist[adjN]){
                ways[adjN]= (ways[adjN] + ways[node])%MOD;
            }
        }
    }
    // return (int)ways[n-1];
    cout<< ways[n-1] <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}