#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> moves{{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool isValid(int row, int col){
  return row>=0 && row<8 && col>=0 && col<8;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a,b; cin >> a >> b;
  a--; b--;
  map< pair<int,int> , vector<pair<int,int>> >adj;
  queue<pair<int,int>> q;
  q.push(make_pair(a,b));
  while(!q.empty()){
    auto [row,col] = q.front();
    q.pop();
    for(auto [r,c] : moves){
      int nr=row+r , nc=col+c;
      if(isValid(nr,nc)){
        adj[make_pair(row,col)].push_back(make_pair(nr,nc));
        q.push(make_pair(nr,nc));
      }
    }
  }


}