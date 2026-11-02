#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,d; cin >> n >> m >> d;
  vector<pair<int,int>> pos(n*m+1);
  for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++){
    int x; cin >> x;
    pos[x]=make_pair(i,j);
  }
  vector<int> pref(n*m+1);
  for(int i=1 ; i<=n*m ; i++){
    if(pref[i] == 0){
      int prv=i;
      for(int j=i+d ; j<=n*m ; j+=d){
        pref[j]=pref[prv]+abs(pos[prv].first-pos[j].first)+abs(pos[prv].second-pos[j].second);
        prv=j;
      }
    }
  }
  // for(auto &x : pref) cout<< x <<" "; cout <<"\n";
  int q; cin >> q;
  for(int i=0 ; i<q ; i++){
    int l,r; cin >> l >> r;
    cout<< pref[r] - pref[l] <<"\n";
  }
}