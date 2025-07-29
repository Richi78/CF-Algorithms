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

vector<pair<int,int>> moves={
    {0,1} , {0,-1} , {1,0} , {-1,0}
};

void bfs(int row, int col, vector<vector<char>> &a, int n, int m, vector<vector<int>> &vis){
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first , c=it.second;
        vis[r][c]=1;
        // a[r][c]='O';
        for(auto [x,y] : moves){
            int new_row=x+r , new_col=y+c;
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m 
                && a[new_row][new_col]=='O' && !vis[new_row][new_col]){
                q.push({new_row,new_col});
            }
        }
    }
}

void dfs(int row, int col, vector<vector<char>> &a, int n, int m, vector<vector<int>> &vis){
    vis[row][col]=1;
    for(auto [x,y] : moves){
        int new_row=x+row , new_col=y+col;
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m 
            && a[new_row][new_col]=='O' && !vis[new_row][new_col]){
            dfs(new_row, new_col, a, n, m, vis);
        }
    }
}


void solve(){
    int n,m; cin >> n >> m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int>(m));

    for(int i=0 ; i<m ; i++){
        if(arr[0][i] == 'O' && !vis[0][i]){
            dfs(0, i, arr, n, m, vis);
        }
        if(arr[n-1][i] == 'O' && !vis[n-1][i]){
            dfs(n-1, i, arr, n, m, vis);
        }
    }
        
    for(int i=0 ; i<n ; i++){
        if(arr[i][0] == 'O' && !vis[i][0]){
            dfs(i, 0, arr, n , m, vis);
        }
        if(arr[i][m-1] == 'O' && !vis[i][m-1]){
            dfs(i, m-1, arr, n , m, vis);
        }
    }
    

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 'O' && vis[i][j]) cout<<"O ";
            else cout<<"X ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}