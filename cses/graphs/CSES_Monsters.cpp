#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;
map<char,pair<int,int>> moves{ {'R',{0,1}}, {'L',{0,-1}}, {'D',{1,0}}, {'U',{-1,0}} };

int n,m; 
vector<pair<int,int>> monsters;
vector<string> a;
vector<vector<pair<int,char>>> vis;
vector<vector<int>> m_path;
vector<pair<int,int>> boundary;
int x_ini , y_ini;

bool isValid(int row, int col){
    return row>=0 && row<n && col>=0 && col<m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    a.resize(n);

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        for(int j=0 ; j<m ; j++){
            if( (j==0 || j==(m-1) || i==0 || i==(n-1)) && (a[i][j]=='.' || a[i][j]=='A') )
                boundary.emplace_back(i,j); 
            if(a[i][j] == 'M') 
                monsters.emplace_back(i,j);
            else if(a[i][j] == 'A')
                x_ini=i , y_ini=j;
        }
    }

    a[x_ini][y_ini]='.';

    m_path.resize(n,vector<int>(m,INF));
    
    queue<array<int,3>> q;
    for(auto [row,col] : monsters) q.push({0,row,col}), m_path[row][col]=0, a[row][col]='.';
    while(!q.empty()){
        auto [dis,r,c] = q.front();
        q.pop();
        for(auto [move,direction] : moves){
            int x=direction.first , y=direction.second;
            int nr=r+x , nc=c+y;
            if(isValid(nr,nc) && a[nr][nc]=='.' && (dis+1)<m_path[nr][nc]){
                q.push({dis+1,nr,nc});
                m_path[nr][nc]=dis+1;
            }
        }
    }
    
    vis.resize(n,vector< pair<int,char> >(m,make_pair(INF,'N')));
    q.push({0,x_ini,y_ini});
    vis[x_ini][y_ini]=make_pair(0,'#');
    while(!q.empty()){
        auto [dis,r,c] = q.front();
        q.pop();
        for(auto [move,direction] : moves){
            int x=direction.first , y=direction.second;
            int nr=r+x , nc=c+y;
            if(isValid(nr,nc) && a[nr][nc]=='.' && vis[nr][nc].second=='N' && (dis+1)<vis[nr][nc].first && (dis+1)<m_path[nr][nc]){
                q.push({dis+1,nr,nc});
                vis[nr][nc]=make_pair(dis+1,move);
            }
        }
    }

    int x=-1,y=-1;
    for(auto [r,c] : boundary){
        if(vis[r][c].first != INF){
            x=r; y=c; break;
        }
    }
    
    if(x==-1 && y==-1){
        cout<<"NO\n"; return 0;
    }

    string ans;
    while(vis[x][y].second != '#'){
        char c=vis[x][y].second;
        ans+=c;
        if(c == 'R') y--;
        else if(c == 'L') y++;
        else if(c == 'U') x++;
        else x--;
    }
    reverse(ans.begin() , ans.end());
    cout<<"YES\n"<<ans.size()<<"\n"<<ans<<"\n";
}