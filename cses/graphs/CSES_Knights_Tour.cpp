#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> moves{{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
vector<vector<int>> board(8, vector<int>(8));

bool isValid(int row, int col){
  return row>=0 && row<8 && col>=0 && col<8 && board[row][col]==0;
}

int getDeg(int row, int col){
  int cnt=0;
  for(auto [x,y] : moves){
    int nr=row+x , nc=col+y;
    if(isValid(nr,nc)) cnt++;
  }
  return cnt;
}

bool dfs(int r, int c, int time){
  board[r][c]=time;
  if(time == 64) return true;
  
  vector< array<int,3> > a;
  for(auto [x,y] : moves){
    int nr=r+x , nc=c+y;
    if(isValid(nr,nc)){
      int deg=getDeg(nr,nc);
      a.push_back( {deg,nr,nc} );
    }
  }
  sort(a.begin() , a.end());
  for(auto [deg,row,col] : a){
    bool tmp = dfs(row,col,time+1);
    if(tmp) return true;
  }
  board[r][c]=0;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a,b; cin >> a >> b;
  a--; b--;
  swap(a,b);

  dfs(a,b,1);
    
  for(auto row : board){
    for(auto col : row){
      cout<< col <<" ";
    }
    cout<<"\n";
  }
}