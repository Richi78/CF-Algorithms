#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n,d; cin >> n >> d;
  vector<pair<int,int>> a;
  for(int i=0 ; i<n ; i++){
    int x,y; cin >> x >> y;
    a.emplace_back(x,y);
  }
  sort(a.begin(), a.end());
  vector<int> pref(n+1);
  int l=0, acc=0;
  int ans=0;
  for(int r=0 ; r<n ; r++){
    acc+=a[r].second;
    while(a[r].first - a[l].first >d){
      acc-=a[l].second;
      l++;
    }
    ans=max(ans,acc+pref[l]);
    pref[r+1]=max(pref[r],acc);
  }
  cout<< ans <<"\n";
}