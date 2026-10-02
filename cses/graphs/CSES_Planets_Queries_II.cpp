
#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<<#x<<": ";for(auto e : x) cout<< e <<" "; cout<<"\n";
#define debug1(x) cout<<#x<<": "<<x<<"\n";

const int LOG = 30;
vector<int> topo;

int walk(int node, vector<vector<int>> &up, int steps){
  for(int k=0 ; k<=LOG ; k++){
    if((steps >> k) & 1){
      node=up[k][node];
    }
  }
  return node;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> a(n);

  // ===================== cycles
  vector<int> indegree(n);
  for(int i=0 ; i<n ; i++){
    int x; cin >> x; x--; a[i]=x;
    indegree[a[i]]++;
  }
  
  queue<int> qq;
  for(int i=0 ; i<n ; i++) if(indegree[i] == 0) qq.push(i);
  while(!qq.empty()){
    int node = qq.front();
    qq.pop();
    topo.push_back(node);
    if(--indegree[a[node]] == 0){
      qq.push(a[node]);
    }
  }

  vector<int> cycle_id(n);
  vector<int> in_cycle(n);
  vector<int> pos(n);
  vector<int> cycle_len(n+1);
  int cycle_number=1;
  for(int i=0 ; i<n ; i++) if(indegree[i] > 0){ // cycle exists
    int p=0;
    for(int node=i ; ; node=a[node]){
      cycle_id[node]=cycle_number;
      in_cycle[node]=1;
      pos[node]=p++;
      indegree[node]=0; // para que no vuelva a entrar a nadie de este ciclo
      if(a[node] == i) break;
    }
    cycle_len[cycle_number]=p;
    cycle_number++;
  }

  vector<int> dist(n);
  for(auto it=topo.rbegin() ; it!=topo.rend() ; it++){
    int node = *it;
    cycle_id[node]=cycle_id[a[node]];
    dist[node] = dist[a[node]]+1;
  }

  // --------------------------------- binary lifting
  vector<vector<int>> up(LOG+1, vector<int>(n));
  for(int i=0 ; i<n ; i++) up[0][i]=a[i];
  for(int k=1 ; k<=LOG ; k++)
    for(int i=0 ; i<n ; i++)
      up[k][i] = up[k-1][up[k-1][i]];

  // -------------------------------  querys

  for(int rep=0 ; rep<q ; rep++){
    // u-> start    v->end
    int u,v; cin >> u >> v; u--; v--;
    // Case 1-> different components
    if(cycle_id[u] != cycle_id[v]){
      cout<< "-1\n"; 
      continue;
    }

    // Case 2-> start in cycle && end out of cycle is impossible
    if(in_cycle[u] && !in_cycle[v]){
      cout<< "-1\n"; 
      continue;
    }

    // Case 3-> start out of cycle && end in cycle possible
    if(!in_cycle[u] && in_cycle[v]){
      int u_to_cycle = walk(u,up,dist[u]);
      int L=cycle_len[cycle_id[v]];
      int dist_cycle = (pos[v] - pos[u_to_cycle] + L)%L;
      cout<< dist[u] + dist_cycle <<"\n"; 
      continue;
    }

    // Case 4-> both in of cycle
    if(in_cycle[u] && in_cycle[v]){
      int L = cycle_len[cycle_id[u]];
      cout<< (pos[v] - pos[u] + L)%L <<"\n"; 
      continue;
    }
    
    // Case 5-> both out of cycle
    if(!in_cycle[u] && !in_cycle[v]){
      if(dist[u] < dist[v]){
        cout<<"-1\n"; 
        continue;
      }
      int d=dist[u] - dist[v];
      if(walk(u,up,d) == v) cout<< d <<"\n";
      else cout<<"-1\n";
      continue;
    }
  }

}