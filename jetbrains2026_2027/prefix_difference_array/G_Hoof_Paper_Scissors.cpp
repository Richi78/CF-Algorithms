#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> H(n) , S(n), P(n);
  for(int i=0 ; i<n ; i++){
    char c; cin >> c;
    if(c == 'P') P[i]++;
    else if(c == 'H') H[i]++;
    else if(c == 'S') S[i]++;
  }
  vector<int> prefH(n+1) , prefS(n+1) , prefP(n+1);
  for(int i=0 ; i<n ; i++){
    prefH[i+1]=prefH[i]+H[i];
    prefS[i+1]=prefS[i]+S[i];
    prefP[i+1]=prefP[i]+P[i];
  }
  int mx=0;
  for(int i=0 ; i<=n ; i++){
    int l=i , r=n;
    int mxP=prefP[i]+max(prefH[r]-prefH[l],prefS[r]-prefS[l]);
    int mxS=prefS[i]+max(prefP[r]-prefP[l],prefH[r]-prefH[l]);
    int mxH=prefH[i]+max(prefP[r]-prefP[l],prefS[r]-prefS[l]);
    mx=max({mx,mxP,mxS,mxH});
  }
  cout<< mx <<"\n";
}