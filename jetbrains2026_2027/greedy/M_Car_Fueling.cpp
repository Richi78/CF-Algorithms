#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int d,l,n; cin >> d >> l >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  int cur=0;
  int cnt=0;
  while(cur<d){
    if(cur+l >= d) break;
    int ll=-1 , rr=n;
    while(rr-ll>1){
      int mid=ll+(rr-ll)/2;
      if(a[mid]<=cur+l) ll=mid;
      else rr=mid;
    }
    if(ll==-1){
      cout<<"-1\n"; return 0;
    }
    if(a[ll]>cur && a[ll]<=cur+l){
      cur=a[ll]; cnt++;
    }else{
      cout<<"-1\n"; return 0;
    }
  }
  cout<< cnt <<"\n";
}