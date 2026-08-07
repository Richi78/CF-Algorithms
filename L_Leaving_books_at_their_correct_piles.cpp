#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<vector<int>> a(n);
  for(int i=0 ; i<n ; i++){
    int size; cin >> size;
    for(int j=0 ; j<size ; j++){
      int x; cin >> x;
      a[i].push_back(x);
    }
  }

  if(n == 1 || n >= 3){
    cout<< "S\n";
  } else{
    for(int i=a[1].size()-1 ; i>=0 ; i--){
      a[0].push_back(a[1][i]);
    } 
    int cnt_1=0 , cnt_2=0;
    for(int i=0 ; i<a[0].size() ; i++){
      if(a[0][i] == 1) cnt_1++;
      else cnt_2++;
    } 
    if(cnt_1==0 || cnt_2==0){
      cout<< "S\n"; return 0;
    }
    bool looking_2=false;
    for(int i=0 ; i<a[0].size() ; i++){
      if(!looking_2 && a[0][i] == 1) continue;
      else if(!looking_2 && a[0][i] == 2) looking_2=true;
      else if(looking_2 && a[0][i] == 1){
        cout<<"N\n"; return 0;
      }
    }
    cout<<"S\n";
  }
}