#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,w; cin >> n >> w;
  vector<pair<int,int>> a;
  for(int i=0 ; i<n ; i++){
    int x,y; cin >> x >> y;
    a.emplace_back(x,y);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long ans=0;
  for(int i=0 ; w>0 && i<n ; i++){
    ans+= 1LL* a[i].first * min(w,a[i].second);
    w-=a[i].second;
  }
  cout<< ans <<"\n";
}