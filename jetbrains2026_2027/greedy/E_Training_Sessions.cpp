#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<array<long long,2>,int>> a;
  for(int i=0 ; i<n ; i++){
    long long x,y; cin >> x >> y;
    a.push_back({{x,y},i});
  }
  sort(a.begin(), a.end(), [&](auto x, auto y){
    return make_pair(x.first[1], x.first[0]) < make_pair(y.first[1], y.first[0]);
  });
  vector<int> ans;
  long long last=0;
  for(int i=0 ; i<n ; i++){
    if(a[i].first[0] >= last){
      ans.push_back(a[i].second);
      last=a[i].first[1];
    }
  }
  cout<< ans.size() <<"\n";
  for(auto &x : ans) cout << x+1 <<" ";
  cout<<"\n";
}