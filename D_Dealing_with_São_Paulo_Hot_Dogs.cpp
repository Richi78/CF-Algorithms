#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": "<<x<<" , "<<#y<<": "<<y<<"\n";
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n,m,p,s; cin >> n >> m >> p >> s;
  vector<pair<int,int>> a;
  for(int i=0 ; i<m ; i++){
    int x,y; cin >> x >> y;
    a.emplace_back(x,y);
  }

  int ans=0;
  for(int mask=1 ; mask<(1<<n) ; mask++){
    bool ok=true;
    // bread;
    int bit_bread=-1;
    for(int i=n-1 ; i>=n-p && ok ; i--){
      if(mask & (1<<i)){
        if(bit_bread != -1) ok=false;
        else bit_bread=i;
      }
    }
    if(bit_bread==-1 || !ok) continue;
    // sausage;
    int bit_sausage=-1;
    for(int i=n-p-1 ; i>=n-(p+s) && ok ; i--){
      if(mask & (1<<i)){
        if(bit_sausage != -1) ok=false;
        else bit_sausage=i;
      }
    }
    if(bit_sausage==-1 || !ok) continue;
    // debug2(bit_bread,bit_sausage)


    // comprobar restricciones de complementos
    bool f=true;
    for(int j=0 ; j<m ; j++){
      // comprobar bit first y second
      if(mask&(1<<(n-a[j].first)) && mask&(1<<(n-a[j].second))){
        f=false; break;
      }
    }
    ans+=f;
  }
  cout<< ans <<"\n";
}