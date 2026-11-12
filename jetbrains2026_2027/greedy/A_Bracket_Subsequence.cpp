#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n=s.size();
  vector<int> suf(n+1);
  for(int i=n-1 ; i>=0 ; i--) suf[i]=suf[i+1]+(s[i]==')'); 
  int cur=0;
  string ans;
  for(int i=0 ; i<n ; i++){
    if(s[i] == '(' && suf[i+1]>cur) cur++ , ans+=s[i];
    else if(s[i] == ')' && cur>0) cur-- , ans+=s[i]; 
  }
  cout<< ans.size() <<"\n";
  cout<< ans <<"\n";
}