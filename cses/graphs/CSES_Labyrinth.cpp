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
    vector<string> a(n,string(m,' '));
    pair<int,int> start,end;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            char c; cin >> c;
            a[i][j]=c;
            if(c=='A') start={i,j};
            else if(c=='B'){
                a[i][j]='.';
                end={i,j};
            } 
        }
    }

    vector<vector<char>> vis(n,vector<char>(m,'@'));
    vector<pair<int,int>> moves={
        {1,0} , {-1,0} , {0,1} , {0,-1}
    };

    queue<array<int,3>> q;
    q.push({0,start.F,start.S});
    vis[start.F][start.S]='.';
    int r=-1 , c=-1 , mn=-1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dist=it[0] , row=it[1] , col=it[2];
        if(row==end.F && col==end.S){
            mn=dist;
            r=row; c=col;
            break;
        }
        for(auto [x,y] : moves){
            char c;
            if(x==1) c='D';
            else if(x==-1) c='U';
            else if(y==1) c='R';
            else c='L';
            int new_row=row+x , new_col=col+y;
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m
                && a[new_row][new_col]=='.' && vis[new_row][new_col]=='@'){
                vis[new_row][new_col]=c;
                q.push({dist+1,new_row,new_col});
            }
        }
    }
    
    if(mn == -1) cout<<"NO\n";
    else{
        cout<<"YES\n"<< mn <<"\n";
        string ans="";
        while(vis[r][c] != '.'){
            ans.push_back(vis[r][c]);
            char tmp=vis[r][c];
            if(tmp=='U') r++;
            else if(tmp=='D') r--;
            else if(tmp=='R') c--;
            else c++;
        }
        reverse(all(ans));
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}