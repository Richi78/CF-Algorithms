#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<long long> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> diff1(n+1) , diff2(n+1);
  for(int i=0 ; i<q ; i++){
    long long l,r,x,d; cin >> l >> r >> x >> d; l--;
    diff1[l]+=x-l*d; diff1[r]-=(x-l*d); 
    diff2[l]+=d; diff2[r]-=d;
  }
  for(int i=0 ; i<n ; i++) diff1[i+1]+=diff1[i] , diff2[i+1]+=diff2[i];
  for(int i=0 ; i<n ; i++){
    a[i] = a[i] + i*diff2[i] + diff1[i];
    cout << a[i] <<" ";
  }
  cout<<"\n";
}