#include <bits/stdc++.h>

using namespace std;

struct Event{
  int x;
  bool isEnd;
  int idx;
  bool operator<(const Event &b) const {
    return make_pair(x,!isEnd) < make_pair(b.x,!b.isEnd);
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m; cin >> n >> m;
  vector<Event> a;
  for(int i=0 ; i<m ; i++){
    int l,r; cin >> l >> r;
    a.push_back(Event{l,false,i});
    a.push_back(Event{r,true,i});
  }
  sort(a.begin() , a.end());
  vector<bool> isCut(n+1);
  vector<int> active;
  int cnt=0;
  for(int i=0 ; i<a.size() ; i++){
    if(isCut[a[i].idx]) continue;
    if(a[i].isEnd){
      cnt++;
      for(auto &x : active) isCut[x]=true;
      active.clear();
    }else{
      active.push_back(a[i].idx); 
    }
  }
  cout<< cnt <<"\n";
}