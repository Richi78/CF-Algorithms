#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<long long> a(n);
  for(auto &x : a) cin >> x;
  vector<long long> diff(n+1);
  for(int i=0 ; i<q ; i++){
    long long l,r,val; cin >> l >> r >> val;
    if(l<=r){
      l--;
      diff[l]+=val; diff[r]-=val; 
    }else{
      l--;
      diff[l]+=val; 
      diff[0]+=val; diff[r]-=val;
    }
  }
  for(int i=1 ; i<=n ; i++) diff[i]+=diff[i-1];
  for(int i=0 ; i<n ; i++)
    cout<< a[i]+diff[i] <<" ";
  cout<<"\n";
}
