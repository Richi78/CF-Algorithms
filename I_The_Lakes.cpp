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
    {1,0} , {-1,0} , {0,1} , {0, -1}
};

int bfs(int row, int col, vector<vector<int>> &a, vector<vector<int>> &vis, int n, int m){
    int ans=0;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        if(vis[r][c]) continue;
        ans+=a[r][c];
        vis[r][c]=1;
        for(auto [x,y] : moves){
            int nr=r+x , nc=c+y;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && a[nr][nc]){
                q.push({nr,nc});
            }
        }
    }
    return ans;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int>(m));

    int mx=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j] && vis[i][j] == 0){
                int tmp=bfs(i , j , a , vis, n, m);
                uax(mx,tmp);
            }
        }
    }
    cout<< mx <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

