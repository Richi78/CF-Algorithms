#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;
int n,m;

map<char,pair<int,int>> moves{{'U',{-1,0}} , {'D',{1,0}} , {'R',{0,1}} , {'L',{0,-1}}};

bool isValid(int row, int col){
  return row>=0 && row<n && col>=0 && col<m;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  int xs,ys;
  vector<pair<int,int>> monsters;
  vector<pair<int,int>> boundary;
  vector<string> a(n);
  for(int i=0 ; i<n ; i++){
    cin >> a[i];
    for(int j=0 ; j<m ; j++){
      if(a[i][j] == 'A'){ // start
        xs=i; ys=j;
      }else if(a[i][j] == 'M'){ // monster
        monsters.emplace_back(i,j);
      }
      if(i==0 || i==n-1){ // boundary
        if(a[i][j] == '.' || a[i][j] == 'A'){
          boundary.emplace_back(i,j);
        }
      }
      if(j==0 || j==m-1){
        if(a[i][j] == '.' || a[i][j] == 'A'){
          boundary.emplace_back(i,j);
        }
      }
    }
  }

  a[xs][ys]='.';
  vector<vector<int>> dist(n,vector<int>(m,INF));
  queue<array<int,3>> q;
  for(auto [x,y] : monsters){
    dist[x][y]=0;
    q.push({x,y,0});
    a[x][y]='.';
  }
  while(!q.empty()){
    auto [r,c,d] = q.front();
    q.pop();
    if(d > dist[r][c]) continue;
    for(auto [ch,m] : moves){
      int nr=r+m.first , nc=c+m.second;
      if(isValid(nr,nc) && a[nr][nc]=='.' && d+1<dist[nr][nc]){
        q.push({nr,nc,d+1});
        dist[nr][nc]=d+1;
      }
    }
  }

  // for(auto row:dist){
  //   for(auto e:row) cout<< (e==INF?-1:e) <<" ";
  //   cout<<"\n";
  // }
  // -1 -1 -1 -1 -1 -1 -1 -1 
  // -1  0  1  2  1  2  3 -1 
  // -1  1 -1  1  0 -1  4 -1 
  // -1  0 -1  2  1 -1  5  6 
  // -1  1 -1 -1 -1 -1 -1 -1 

  vector<vector<char>> path(n,vector<char>(m,'N'));
  path[xs][ys]='*';
  q.push({xs,ys,0});
  while(!q.empty()){
    auto [r,c,d] = q.front();
    q.pop();
    if(d>=dist[r][c]) continue;
    for(auto [ch,m] : moves){
      int nr=r+m.first , nc=c+m.second;
      if(isValid(nr,nc) && a[nr][nc]=='.' && d+1<dist[nr][nc] && path[nr][nc]=='N'){
        q.push({nr,nc,d+1});
        path[nr][nc]=ch;
      }
    }
  }
  // cout<<"---------------------------\n";
  // for(auto row:path){
  //   for(auto e:row) cout<< e <<" ";
  //   cout<<"\n";
  // }

  int xe , ye;
  bool ok=false;
  for(auto [x,y] : boundary){
    if(path[x][y] != 'N'){
      ok=true; xe=x; ye=y; break;
    }
  }

  if(!ok){
    cout<< "NO\n"; return 0;
  }

  string ans;
  while(path[xe][ye] != '*'){
    char c=path[xe][ye];
    ans += c;
    if(c == 'U') xe++;
    if(c == 'D') xe--;
    if(c == 'R') ye--;
    if(c == 'L') ye++;
  }
  reverse(ans.begin() , ans.end());
  cout<< "YES\n" << ans.size() <<"\n"<< ans <<"\n";
}