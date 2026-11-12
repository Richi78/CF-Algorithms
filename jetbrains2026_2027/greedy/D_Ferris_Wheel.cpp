#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,w; cin >> n >> w;
  vector<int> a(n);
  for(int i=0 ; i<n ; i++) cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int ans=0;
  for(int i=0 , j=n-1 ; i<=j ; ){
    if(i == j){
      ans++; break;
    }
    if(a[i]+a[j] <= w) ans++ , i++ , j--;
    else if(a[i]+a[j] > w) ans++ , i++;
  }  
  cout<< ans <<"\n";
}