#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,k; cin >> n >> k;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> pref(n+1);
  for(int i=0 ; i<n ; i++) pref[i+1]=pref[i]+a[i];
  map<long long, long long> mp;
  long long ans=0;
  for(int i=0 ; i<=n ; i++){
    long long x=(pref[i]%k + k)%k;
    ans+=mp[x];
    mp[x]++;
  }
  cout<< ans <<"\n";
}