#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n) , freq(2*n+1); 
  for(auto &x : a) cin >> x , freq[x]++;
  vector<int> b;
  for(int i=1 ; i<=2*n ; i++)if(freq[i]==0) b.push_back(i);
  sort(a.begin(), a.end()); reverse(a.begin(), a.end());
  sort(b.begin(), b.end()); reverse(b.begin(), b.end());
  int ans=0;
  for(int i=0 , j=0 ; i<n && j<n ; ){
    if(b[j]>a[i]) ans++ , i++ , j++;
    else i++;
  }
  cout<< ans <<"\n";
}