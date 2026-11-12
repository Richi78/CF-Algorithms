#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<int,int>> a;
  long long ans=0;
  for(int i=0 ; i<n ; i++){
    int x,y; cin >> x >> y;
    a.emplace_back(x,y);
    ans+=y;
  }
  sort(a.begin() , a.end());
  long long sum=0;
  for(auto &[x,y] : a){
    ans-=sum+x;
    sum+=x;
  }
  cout<< ans <<"\n";
}