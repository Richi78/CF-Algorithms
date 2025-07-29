#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }
    vector<pair<int,int>> moves={ {1,0} , {-1,0} , {0,1} , {0,-1} };

    vector<vector<int>> vis(n,vector<int>(m));
    queue<pair<int,int>> q;

    for(int i=0 ; i<m ; i++){
        if(grid[0][i] == 1 && !vis[0][i]){ 
            q.push({0,i});
            vis[0][i]=1;
        }
        if(grid[n-1][i] == 1 && !vis[n-1][i]){
            q.push({n-1,i});
            vis[n-1][i]=1;
        } 
    }
    
    for(int i=0 ; i<n ; i++){
        if(grid[i][0] == 1 && !vis[i][0]){ 
            q.push({i,0});
            vis[i][0]=1;
        }
        if(grid[i][m-1] == 1 && !vis[i][m-1]){
            q.push({i,m-1});
            vis[i][m-1]=1;
        } 
    }

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first , col=it.second;
        for(auto [x,y] : moves){
            int new_row=row+x , new_col=col+y;
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m 
                && grid[new_row][new_col]==1 && !vis[new_row][new_col]){
                vis[new_row][new_col]=1;
                q.push({new_row,new_col});
            }
        }
    }

    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]==1 && !vis[i][j]) cnt++;
        }
    }
    cout<< cnt <<"\n"; 
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}