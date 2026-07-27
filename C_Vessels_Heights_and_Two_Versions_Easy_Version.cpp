#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;
  for(int rep=0 ; rep<n ; rep++){
    vector<int> w1(n), w2(n), w(n);
    for(int i=1 ; i<n ; i++){
      w1[(rep+i)%n] = max(w1[(rep+i-1)%n], a[(rep+i-1)%n]);
    }
    for(int i=1 ; i<n ; i++){
      w2[(rep+n-i)%n] = max(w2[(rep+n-i+1)%n] , a[(rep+n-i)%n]);
    }
    for(int i=0 ; i<n ; i++){
      w[i]=min(w1[i],w2[i]);
    }
    cout<< accumulate(w.begin() , w.end() , 0LL) <<" ";
  }
  cout<<"\n";
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