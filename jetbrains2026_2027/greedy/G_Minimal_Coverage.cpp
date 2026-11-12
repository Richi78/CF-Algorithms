#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<array<int,3>> a;
  for(int i=0 ; i<n ; i++){
    int l,r; cin >> l >> r;
    a.push_back({max(0,l),r,i});
  }
  sort(a.begin(), a.end());
  vector<array<int,3>> st;
  int cur=0;
  for(auto &[l,r,idx] : a){
    if(cur>=m) break;
    if(l<=cur && r>cur){
      while(st.size()>1 && l<=st[st.size()-2][1]) st.pop_back();
      if(st.size()==1 && l<=0 && r>st[st.size()-1][1]) st.pop_back();
      st.push_back({max(0,l),r,idx});
      cur=r;
    }
  }
  cout<< (cur<m ? -1 : (int)st.size()) <<"\n";
}