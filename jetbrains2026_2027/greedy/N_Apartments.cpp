#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  long long n,m,k; cin >> n >> m >> k;
  vector<long long> a(n);
  multiset<long long> st;
  for(auto &x : a) cin >> x;
  for(int i=0 ; i<m ; i++){
    long long x; cin >> x;
    st.insert(x);
  } 
  sort(a.begin() , a.end());
  int ans=0;
  for(int i=0 ; i<n ; i++){
    auto it=st.lower_bound(a[i]-k);
    if(it==st.end()) continue;
    if((a[i]-k)<=*it && *it<=(a[i]+k)){
      st.erase(it); 
      ans++;
    }
  }
  cout<< ans <<"\n";
}