#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n,k; cin >> n >> k;
  vector<int> a(n);
  for(auto &x : a) cin >> x;

  vector<int> len;
  int cur=1;
  for(int i=1 ; i<n ; i++){
    if(a[i] != a[i-1]) len.push_back(cur) , cur=1;
    else cur++;
  }
  len.push_back(cur);

  sort(len.begin() , len.end());

  int m=len.size();
  int i=0 , ans=0 , d=0;
  while(i < m){
    int s=len[i];
    int x=s-1; // destroyed elements of current block
    int q=m-i; // remaining blocks
    int current = n - d - x*q;
    if(current<=k && (k-current)%q==0){
      ans++;
    }

    int j=i;
    while(j<m && len[j] == len[i]) j++;
    d+=(j-i)*len[i];
    i=j;
  }
  cout << ans <<"\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while(tc--){
    solve();
  }
  return 0;
}