#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> team;
bool bfs(int x, vector<int> adj[]){
    queue<pair<int,int>> q;
    q.push(make_pair(x,1));
    team[x]=1;
    while(!q.empty()){
        auto [node,color] = q.front();
        q.pop();
        for(int adjN : adj[node]){
            if(team[adjN]==-1){
                team[adjN]=color^1;
                q.push(make_pair(adjN,team[adjN]));
            }else if(team[adjN]==color){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<int> adj[n];

    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    team.resize(n,-1);

    for(int i=0 ; i<n ; i++){
        if(team[i]==-1){
            bool tmp=bfs(i,adj);
            if(!tmp){
                cout<<"IMPOSSIBLE\n"; return 0;
            }
        }
    }

    for(auto &x : team) cout<< x+1 <<" ";
    cout<<"\n";

    return 0;
}