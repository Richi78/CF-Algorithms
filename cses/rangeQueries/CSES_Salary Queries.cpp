#include <bits/stdc++.h>

using namespace std;

vector<int> st;
int BASE=1;

void update(int idx, int val){
  st[idx+BASE]+=val;
  for(int i=(idx+BASE)/2 ; i>=1 ; i>>=1){
    st[i]=st[2*i]+st[2*i+1];
  }
}

int _get(int node, int l, int r, int ql, int qr){
  if(r<ql || qr<l) return 0;
  if(ql<=l && r<=qr) return st[node];
  int mid=l+(r-l)/2;
  int left=_get(2*node,l,mid,ql,qr);
  int right=_get(2*node+1,mid+1,r,ql,qr);
  return left+right;
}

int get(int l, int r){
  return _get(1,0,BASE-1,l,r);
}

int query(int l, int r) {
  int res = 0;
  for (l += BASE, r += BASE + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += st[l++];
    if (r & 1) res += st[--r];
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  vector<int> b(a.begin(),a.end());
  vector<pair<char,array<int,2>>> qq;
  for(int rep=0 ; rep<q ; rep++){
    char t; int x,y; cin >> t >> x >> y;
    qq.push_back({t,{x,y}});
    b.push_back(x); b.push_back(y);
  }
  sort(b.begin() , b.end());
  b.resize(unique(b.begin() , b.end()) - b.begin());
  for(auto &x : a){
    x = lower_bound(b.begin(), b.end(), x) - b.begin();
  }
  int N=b.size();
  while(BASE < N) BASE<<=1;
  st.resize(2*BASE);
  for(int i=0 ; i<n ; i++) st[a[i]+BASE]++;
  for(int i=BASE-1 ; i>=1 ; i--) st[i]=st[2*i]+st[2*i+1];

  for(auto e : qq){
    char t = e.first;
    if(t == '!'){ // point update
      int k=e.second[0] , x=e.second[1];
      update(a[k-1], -1);
      x = lower_bound(b.begin() , b.end() , x) - b.begin();
      a[k-1]=x;
      update(x, 1);
    }else{ // range query
      int l=e.second[0] , r=e.second[1];
      l = lower_bound(b.begin() , b.end() , l) - b.begin();
      r = lower_bound(b.begin() , b.end() , r) - b.begin();
      cout<< query(l,r) <<"\n";
    }
  }
}