#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<int,int>> a;
  for(int i=0 ; i<n ; i++){
    int c,w; cin >> c >> w;
    a.emplace_back(c,w);
  }
  sort(a.begin(), a.end(), [&](auto x, auto y){return x.second > y.second;});
  long long ans=0;
  int i=0 , j=n-1;
  while(i<=j){
    auto &[c1,w1] = a[i];
    auto &[c2,w2] = a[j];
    ans=max(ans,1LL*w1+w2);
    if(c1 > c2) j-- , c1-=c2;
    else i++ , c2-=c1;
  }
  cout<< ans <<"\n";
}