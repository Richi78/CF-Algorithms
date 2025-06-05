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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

vector< pair<int,int> > mov={
    {0,-1} , {0,1} , {-1,0} , {1,0}
};

int bfs(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<int>> &vis){
    queue<pair<int,int>> q;
    q.push({i,j});

    int cnt=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.F , y=it.S;
        // debug2(x,y)
        if(vis[x][y]) continue;
        vis[x][y]=1;
        cnt+=a[x][y];
        for(auto [l,r] : mov){
            if(x+l<0 || x+l>n || y+r<0 || y+r>m)continue;
            if(vis[x+l][y+r]) continue;
            if(a[x+l][y+r]) q.push({x+l,y+r});
        }
    }
    return cnt;
}

void solve(){
    int n,m; cin >> n >> m;
    vector< vector<int> > a(n,vector<int>(m)), vis(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin >> a[i][j];
    }

    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j] && vis[i][j] == 0){
                int tmp=bfs(i, j, n-1, m-1, a, vis);
                cnt=max(cnt,tmp);
            }
        }
    }
    cout<< cnt <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}