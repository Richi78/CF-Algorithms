#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n,d; cin >> n >> d;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  long long left=0 , right=0;
  {//left
    int copy_d=d;
    for(int i=n-1 ; i>=0 && copy_d>0 ; i-- , copy_d--){
      left+=a[i]; 
    }
  }
  {//right
    int copy_d=d;
    for(int i=1 ; i<n && copy_d>0; i++ , copy_d--){
      right+=a[i];
    }
  }
  int idxl=n-d , idxr=d;
  long long ans=0;
  for(int i=0 ; i<n ; i++){
    long long tmp=2LL*d*a[i] - left - right;
    if(tmp > 0) ans+=tmp;
    left+=a[i];
    left-=a[idxl]; 
    idxl=(idxl+1)%n;

    idxr=(idxr+1)%n;
    right+=a[idxr];
    right-=a[(i+1)%n];
  }
  cout<<ans<<"\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while(tc--){
    solve();
  }
  return 0;
}