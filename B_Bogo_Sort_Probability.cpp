#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int MOD=1e9+7;

int binexp(int a , int b){
  int ans=1;
  while(b){
    if(b&1) ans=ans*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return ans;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q; cin >> n >> q;
  map<int,int> mp;
  vector<int> a(n);
  for(auto &x : a){
    cin >> x;
    mp[x]++;
  } 

  vector<int> fact(n+1);
  fact[0]=1;
  for(int i=1 ; i<=n ; i++){
    fact[i]=i*fact[i-1]%MOD;
  }
  int invN = binexp(fact[n] , MOD-2);

  int num=1;
  for(auto [x,y] : mp){
    num = num * fact[y] %MOD;
  }

  int x = num * invN %MOD;
  cout<< x <<"\n";

  for(int rep=0 ; rep<q ; rep++){
    int pos,val; cin >> pos >> val;
    pos--;
    num = num * binexp(mp[a[pos]], MOD-2) %MOD;
    mp[a[pos]]--;
    a[pos]=val;
    mp[a[pos]]++;
    num = num * mp[a[pos]] %MOD;
    x = num * invN %MOD;
    cout<< x <<"\n";
  }
}