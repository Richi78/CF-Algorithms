#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<long long> a(n); 
  for(auto &x : a) cin >> x;
  long long mx=-1e18 , cur=0;
  for(int i=0 ; i<n ; i++){
    cur=max(cur+a[i],a[i]);
    mx=max(mx,cur);
  }
  cout<< mx <<"\n";
}