#include <bits/stdc++.h>

using namespace std;

int n,k;

bool isValid(int row, int col){
  return row>=0 && row<n && col>=0 && col<n;
}

int main(){
  cin >> n >> k;
  vector<vector<int>> a(n,vector<int>(n));
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      cin >> a[i][j];
    }
  }
  k--;
  int ans=0;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      int me=a[i][j];
      if(isValid(i,j+k) && isValid(i+k,j) && isValid(i+k,j+k) && me==a[i][j+k] && me==a[i+k][j] && me==a[i+k][j+k]){
        ans++;
      }
    }
  }
  cout<< ans <<"\n";
}