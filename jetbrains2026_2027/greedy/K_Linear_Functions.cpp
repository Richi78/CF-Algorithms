#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<array<int,3>> a;
  for(int i=0 ; i<n ; i++){
    int x,y; cin >> x >> y;
    a.push_back({x,y,i});
  }
  sort(a.begin() , a.end(), [&](auto x, auto y){
    return 1LL*x[0]*y[1]+x[1] < 1LL*y[0]*x[1]+y[1];
  });
  for(auto &[x,y,idx] : a) cout<< idx+1 <<" ";
  cout<<"\n";
}