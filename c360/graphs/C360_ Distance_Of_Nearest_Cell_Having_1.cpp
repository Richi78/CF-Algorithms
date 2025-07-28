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
    {1,0} , {-1,0} , {0,1} , {0,-1}
};

void bfs(vector<vector<int>> &a, vector<vector<int>> &vis, int n, int m, vector<pair<int,int>> &active){

    queue<array<int,3>> q;
    for(int i=0 ; i<(int)active.size() ; i++){
        q.push({0,active[i].first,active[i].second});
    }

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dist=it[0] , row=it[1] , col=it[2];
        if(dist >= vis[row][col]) continue;
        vis[row][col]=dist;
        for(auto [x,y] : moves){
            int new_row=row+x , new_col=col+y;
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m){
                q.push({dist+1,new_row,new_col});
            }
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> mat[i][j];
        }
    }


    vector<vector<int>> vis(n,vector<int>(m,1e9));
    vector<pair<int,int>> active;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == 1){
                active.emplace_back(i,j);
            }
        }
    }

    bfs(mat, vis, n , m, active);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout<< vis[i][j] <<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}