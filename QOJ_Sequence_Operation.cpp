#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;

  vector<bool> vis(n+1);
  int ops=0;
  int mex=0;
  if(a.back()<n-1){
    for(int i=0 ; i<n ; i++){
      while(!vis[mex])mex++;
      
    }
  }

  cout<< a.back() <<" "<< ops <<"\n";
}

int main(){
  int tc; cin >> tc;
  while(tc--) solve();
}