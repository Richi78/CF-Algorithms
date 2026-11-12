#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<string> a(n);
  for(auto &x : a) cin >> x;
  sort(a.begin() , a.end() , [&](auto x, auto y){
    return x+y > y+x;
  });
  bool allZeros=true;
  for(int i=0 ; i<n ; i++) allZeros&=(a[i]=="0");
  if(allZeros){
    cout<< "0\n"; return 0;
  }
  for(auto &x : a) cout<< x;
  cout<<"\n";
}