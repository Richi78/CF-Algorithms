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

  int n; cin >> n;
  vector<Event> a;
  for(int i=0 ; i<n ; i++){
    int h,m,s; cin >> h >> m >> s;
    int x=h*3600+m*60+s;
    cin >> h >> m >> s;
    int y=h*3600+m*60+s;
    if(x < y){
      a.push_back(Event{x , false , i});
      a.push_back(Event{y , true , i});
    }else{
      a.push_back(Event{x , false , i});
      a.push_back(Event{24*3600 , true , i});
      a.push_back(Event{0 , false , i});
      a.push_back(Event{y , true , i});
    }
  }
  sort(a.begin() , a.end());
  // for(auto x : a){
  //   cout<<(x.isEnd?"FIN:":"INI:")<< x.x <<":"<<x.idx<<" ";
  // }
  cout<<"\n";
  int sz=a.size();
  int cnt=0;
  int ans=0;
  int b=-1;
  for(int i=0 ; i<sz ; i++){
    if(!a[i].isEnd){
      cnt++;
      if(cnt == n){
        b=a[i].x;
      }
    }else{
      if(cnt == n){
        ans+=a[i].x-b;
      }
      cnt--;
    } 
  }
  cout<< ans <<"\n";
}