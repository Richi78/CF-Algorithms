#include <bits/stdc++.h>

using namespace std;

struct Event{
  int x;
  bool isEnd;
  int idx;
  bool operator<(const Event& b) const {
    return make_pair(x,isEnd) < make_pair(b.x,b.isEnd);
  }
};

int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<Event> a;
  for(int i=0 ; i<n ; i++){
    int ini,fin; cin >> ini >> fin;
    a.push_back(Event{ini,false,i});
    a.push_back(Event{fin,true,i});
  }
  sort(a.begin() , a.end());
  queue<int> active;
  int cnt=0;
  active.push(cnt);
  vector<int> ans(n);
  for(int i=0 ; i<2*n ; i++){
    if(a[i].isEnd == false){
      if(active.size() == 0){
        cnt++;
        active.push(cnt);
      }
      ans[a[i].idx]=active.front();
      active.pop();
    }else{
      active.push(ans[a[i].idx]);
    }
  }
  cout<< cnt+1 <<"\n";
  for(auto &x : ans) cout<< x+1 <<" ";
  cout<<"\n";
}