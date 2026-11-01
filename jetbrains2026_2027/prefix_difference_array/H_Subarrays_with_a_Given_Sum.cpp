#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  long long n,S; cin >> n >> S;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> pref(n+1);
  for(int i=0 ; i<n ; i++) pref[i+1]=pref[i]+a[i];
  map<long long, long long> mp;
  long long ans=0;
  for(int i=0 ; i<=n ; i++){
    ans+=mp[pref[i]-S];
    mp[pref[i]]++;
  }
  cout<< ans <<"\n";
}