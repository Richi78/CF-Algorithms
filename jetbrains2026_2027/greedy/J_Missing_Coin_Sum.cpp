#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  sort(a.begin() , a.end());
  long long cur=0;
  for(int i=0 ; i<n ; i++){
    if(a[i] <= cur+1) cur+=a[i];
    else break;
  }
  cout<< cur+1 <<"\n";
}