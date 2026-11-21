#include <bits/stdc++.h>

using namespace std;

int BASE=1;
vector<int> st;

void update(int idx){
  st[idx+BASE]=0;
  for(int i=(idx+BASE)/2 ; i>=1 ; i>>=1) st[i]=st[2*i]+st[2*i+1];
}

int _get(int node, int l, int r, int k){
  if(l == r) return l;
  int mid = l+(r-l)/2;
  if(k <= st[2*node]) return _get(2*node, l, mid, k);
  return _get(2*node+1, mid+1, r, k-st[2*node]);
}

int get(int k){
  return _get(1,0,BASE-1,k);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  while(BASE<n) BASE<<=1;
  st.resize(2*BASE);
  for(int i=0 ; i<n ; i++) st[i+BASE] = 1;
  for(int i=BASE-1 ; i>=1 ; i--) st[i]=st[2*i]+st[2*i+1];

  for(int rep=0 ; rep<n ; rep++){
    int k; cin >> k;
    int idx = get(k);
    update(idx);
    cout<< a[idx] <<" ";
  }
  cout<<"\n";
}