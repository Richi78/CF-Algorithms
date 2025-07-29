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

void dfs(int row, int col, vector<vector<int>> &a, vector<vector<bool>> &vis, 
    vector<pair<int,int>> &tmp, int n, int m){
    vis[row][col]=true;
    tmp.emplace_back(row,col);
    for(auto [x,y] : moves){
        int new_row=row+x , new_col=col+y;
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m
            && !vis[new_row][new_col] && a[new_row][new_col]==1){
                dfs(new_row, new_col, a, vis, tmp, n, m);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >>arr[i][j];
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m));
    set<vector<pair<int,int>>> st;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(vis[i][j] == false && arr[i][j]==1){
                vector<pair<int,int>> tmp;
                dfs(i, j, arr, vis, tmp, n , m);
                int row_base=tmp[0].first , col_base=tmp[0].second;
                for(int k=0 ; k<(int)tmp.size() ; k++){
                    tmp[k].first-=row_base;
                    tmp[k].second-=col_base;
                }
                st.insert(tmp);
            }
        }
    }
    cout<< st.size() <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}