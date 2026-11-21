#include <bits/stdc++.h>

using namespace std;

struct Event{
  int x;
  bool isEnd;
  int idx;
  bool isP;
  bool operator<(const Event &b) const {
    array<int,3> a={x,isEnd,isP};
    array<int,3> c={b.x,b.isEnd,b.isP};
    return a<c;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<Event> a;
  for(int i=0 ; i<n ; i++){
    int l,r; cin >> l >> r; 
    a.push_back(Event{min(l,r),false,i,false});
    a.push_back(Event{max(l,r),true,i,false});
  }
  for(int i=0 ; i<m ; i++){
    int x; cin >> x;
    a.push_back(Event{x,false,i,true});
  }
  sort(a.begin() , a.end());
  vector<int> ans(m);
  int cnt=0;
  for(int i=0 ; i<a.size() ; i++){
    if(a[i].isP) ans[a[i].idx]=cnt;
    else if(a[i].isEnd) cnt--;
    else cnt++;
  }
  for(auto &x : ans) cout<< x <<" ";
  cout<<"\n";
}