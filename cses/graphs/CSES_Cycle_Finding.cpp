#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        edges[i]={u,v,w};
    }
    
    vector<long long> dp(n);
    vector<int> parent(n,-1);

    for(int rep=0 ; rep<n-1 ; rep++){
        for(auto &[u,v,w] : edges){
            if(dp[u]+w < dp[v]){
                dp[v]=dp[u]+w;
                parent[v]=u;
            }
        }
    }

    int last_relaxed=-1;
    for(auto &[u,v,w] : edges){
        if(dp[u]+w < dp[v]){
            dp[v]=dp[u]+w;
            parent[v]=u;
            last_relaxed=v;
        }
    }


    if(last_relaxed == -1){
        cout<<"NO\n"; return 0;
    }

    for(int i=0 ; i<n ; i++){
        last_relaxed = parent[last_relaxed];
    }

    vector<int> cycle;
    for(int cur=last_relaxed; ; cur=parent[cur]){
        cycle.push_back(cur);
        if(cur == last_relaxed && cycle.size()>1) break;
    }
    reverse(cycle.begin() , cycle.end());
    cout<<"YES\n";
    for(auto &x : cycle) cout<< x+1 <<" ";
    cout<<"\n";
}