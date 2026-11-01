#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  long long ans=0;
  for(auto &x : a){
    ans+=x; 
    cout<< ans <<" ";
  }
  cout<<"\n";
}