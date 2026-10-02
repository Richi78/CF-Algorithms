#include <bits/stdc++.h>

using namespace std;

const int LOG=30;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  vector<int> indegree(n);
  for(int i=0 ; i<n ; i++){
    int x; cin >> x; x--; 
    a[i]=x; indegree[x]++;
  }

  vector<int> topo;
  queue<int> q;
  for(int i=0 ; i<n ; i++) if(indegree[i] == 0) q.push(i);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    if(--indegree[a[node]] == 0){
      q.push(a[node]);
    }
  }

  vector<int> in_cycle(n);
  vector<int> cycle_len(n+1);
  int cycle_number=1;
  for(int i=0 ; i<n ; i++) if(indegree[i] > 0){
    int pos=0;
    for(int node=i ; ; node=a[node]){
      in_cycle[node]=cycle_number;
      indegree[node]=0;
      pos++;
      if(a[node] == i) break;
    }
    cycle_len[cycle_number]=pos;
    cycle_number++;
  }

  vector<int> dist(n);
  for(auto it=topo.rbegin() ; it!=topo.rend() ; it++){
    int node = *it;
    in_cycle[node]=in_cycle[a[node]];
    dist[node]=dist[a[node]]+1;
  }

  for(int i=0 ; i<n ; i++){
    cout<< dist[i] + cycle_len[in_cycle[i]] <<" ";
  }
  cout<<"\n";
}