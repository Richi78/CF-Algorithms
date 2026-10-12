#include <bits/stdc++.h>

using namespace std;

const int LOG = 30;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> a(n,-1);
  for(int i=1 ; i<n ; i++) cin >>a[i], a[i]--;
  vector<vector<int>> up(LOG+1, vector<int>(n));
  for(int i=0 ; i<n ; i++){
    up[0][i]=a[i];
  }
  for(int i=1 ; i<=LOG ; i++){
    for(int j=0 ; j<n ; j++){
      if(up[i-1][j] == -1) 
        up[i][j] = -1;
      else 
        up[i][j] = up[i-1][up[i-1][j]];
    }
  }

  for(int rep=0 ; rep<q ; rep++){
    int e,step; cin >> e >> step;
    e--;
    for(int i=0 ; i<=LOG && e!=-1 ; i++){
      if((step>>i) & 1){
        e = up[i][e];
      }
    }
    cout<< (e == -1 ? -1 : e+1) <<"\n";
  }
}