#include <bits/stdc++.h>

using namespace std;

const int N=1e6+100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  vector<vector<int>> pf(N);
  vector<bool> prime(N,true);
  for(int i=2 ; i<N ; i++){
    if(prime[i]){
      for(int j=i ; j<N ; j+=i){
        pf[j].push_back(i); prime[j]=false;
      }
    }
  }

  int n; cin >> n;
  set<pair<int,int>> st; // cnt, p
  vector<int> cnt(N);
  vector<bool> state(N);
  for(int rep=0 ; rep<n ; rep++){
    int x; cin >> x;
    state[x]=!state[x];
    int op=state[x]?1:-1;
    for(auto p : pf[x]){
      auto it = st.find(make_pair(cnt[p],p));
      if(it != st.end()) st.erase(it);
      cnt[p]+=op;
      st.insert(make_pair(cnt[p],p));
    }
    cout<< prev(st.end())->first <<"\n";
  }
}