#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int ans=0;
  for(auto c : s){
    if(c=='6' || c=='8' || c=='0') continue;
    ans++;
  }
  cout<< ans <<"\n";
}