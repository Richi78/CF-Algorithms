#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n; cin >> n;
  vector<pair<int,int>> a(n); 
  for(int i=0 ; i<n ; i++){
    int x; cin >> x;
    a[i].first = x;
    if(i&1) a[i].second=1;
    else a[i].second=0;
  }
  sort(a.begin() , a.end());

  for(int i=0 ; i<n ; i++){
    if(i+1<n && a[i].second == a[i+1].second){
      cout<<"NO\n"; return;
    }
  }
  cout<<"YES\n";
}

int main(){
  int tc; cin >> tc;
  while(tc--) solve();
}