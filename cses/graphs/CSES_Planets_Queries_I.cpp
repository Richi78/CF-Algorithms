#include <bits/stdc++.h>

using namespace std;

const int LOG = 30;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;
  vector<vector<int>> up(LOG+1, vector<int>(n));
  for(int i=0 ; i<n ; i++){
    int x; cin >> x; x--; up[0][i]=x;
  }

  for(int k=1 ; k<=LOG ; k++) for(int i=0 ; i<n ; i++){
    up[k][i] = up[k-1][up[k-1][i]];
  }
  
  for(int rep=0 ; rep<q ; rep++){
    int u,step; cin >> u >> step; u--;
    for(int k=0; k<=LOG ; k++){
      if((step>>k) & 1){
        u = up[k][u];
      }
    }
    cout<< u+1 <<"\n";
  }
}