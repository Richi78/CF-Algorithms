#include <bits/stdc++.h>

using namespace std;

#define vdebug(x) cout<< #x <<": "; for(auto e:x) cout<< e <<" "; cout<<"\n";
#define debug1(x) cout<< #x << ": " << x <<"\n";
const int INF=1e9+7;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  vector<int> copy_a(a.begin() , a.end());
  sort(copy_a.begin() , copy_a.end());
  int med = copy_a[n/2];

  vector<int> dp(n+1, -n);
  dp[0]=0;
  for(int l=0 ; l<n ; l++){
    int s=0 , b=0;
    for(int r=l ; r<n ; r++){
      s+=a[r]<med; b+=a[r]>med;
      if(((r-l+1)&1) && s<=(r-l+1)/2 && b<=(r-l+1)/2){
        dp[r+1]=max(dp[r+1], dp[l]+1);
      }
    }
  }
  // vdebug(dp)
  cout<< dp[n] <<"\n";
}

int main(){
  int tc; cin >> tc;
  while(tc--) solve();
  return 0;
}