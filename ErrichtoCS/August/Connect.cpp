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

vector<pair<int,int>> bfs(int row, int col, vector<string> &a, vector<vector<int>> &vis, int &cnt, int n){
    vector<pair<int,int>> ans;
    vis[row][col]=cnt;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.F , c=it.S;
        ans.emplace_back(r,c);
        for(auto [x,y] : moves){
            int new_row=r+x , new_col=c+y;
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<n  
                && vis[new_row][new_col]==0 && a[new_row][new_col]=='0'){
                vis[new_row][new_col]=cnt;
                q.push({new_row,new_col});
            }
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    pair<int,int> start,end;
    cin >> start.F >> start.S >> end.F >> end.S;

    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<vector<pair<int,int>> > components;
    vector<vector<int>> vis(n, vector<int>(n));
    int cnt=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(vis[i][j]==0 && a[i][j]=='0'){
                cnt++;
                vector<pair<int,int>> tmp=bfs(i,j,a,vis,cnt,n);
                components.push_back(tmp);
            }
        }
    }

    int stComp=vis[start.F-1][start.S-1] , endComp=vis[end.F-1][end.S-1];
    if(stComp == endComp){
        cout<<"0\n"; return;
    }
    // comp 1 is in pos 0 , comp 2 is in pos 1
    int ans=1e18;
    for(auto [x,y] : components[stComp-1]){
        for(auto [z,w] : components[endComp-1]){
            uin(ans,(x-z)*(x-z)+(y-w)*(y-w));
        }
    }
    cout<< ans <<"\n";
    // for(auto x : vis){
    //     vdebug(x)
    // }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}