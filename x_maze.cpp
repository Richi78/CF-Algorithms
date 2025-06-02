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

void left(vector<vector<int>> &a, int x, int y){
    a[x][y+2]=1;
    a[x+1][y+3]=1;
    a[x+2][y]=1;
    a[x+3][y+1]=1;
}

void right(vector<vector<int>> &a, int x, int y){
    a[x][y+1]=1;
    a[x+1][y]=1;
    a[x+2][y+3]=1;
    a[x+3][y+2]=1;
}

int bfs(vector<vector<int>> &board, vector<pair<int,int>> &mov, vector<vector<int>> &vis, int x, int y, int h, int w){
    // debug2(h,w)
    int cnt=0;
    if(vis[x][y] == 1) return cnt; 
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto tmp=q.front();
        q.pop();
        int a=tmp.F , b=tmp.S;
        if(vis[a][b] == 1){
            return cnt;
        }
        
        // debug2(a,b)
        vis[a][b]=1; cnt++;
        for(auto m : mov){
            int tmpa=a+m.F , tmpb=b+m.S;
            if(tmpa>=h*4 || tmpa<0 || tmpb>=w*4 || tmpb<0) continue;
            if(vis[tmpa][tmpb] == 1)continue;
            if(board[tmpa][tmpb] == 1) q.push({tmpa,tmpb});
        }
    }
    return 0;
}

pair<int,int> solve(int x, int y, vector<pair<int,int>> &mov){
    vector< vector<int> > a(4*x, vector<int>(4*y,0));
    string s;
    // representacion apropiada para la matriz
    for(int i=0 ; i<x ; i++){
        cin >> s;
        for(int j=0 ; j<y ; j++){
            char c=s[j];
            if(c=='/') right(a , i*4 , j*4);
            else left(a , i*4 , j*4);
        }
    }
    
    
    vector< vector<int> > vis(4*x,vector<int>(4*y,0));
    // for(int i=0 ; i<x*4 ; i++){
    //     for(int j=0 ; j<y*4 ; j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    pair<int,int> ans;
    int mx=-1 , cnt=0;
    for(int i=0 ; i<x*4 ; i++){
        for(int j=0 ; j<y*4 ; j++){
            if(vis[i][j]==0 && a[i][j]==1){
                int cur= bfs(a,mov,vis,i,j,x,y);
                if(cur>0){
                    cnt++;
                    uax(mx,cur);
                    ans={cnt,mx};
                }
            }
        }
    }
    
    return ans;
    
    
}

signed main(){
    FIO;
    int x,y;
    vector< pair<int,int> > mov;
    for(int i=-1 ; i<2 ; i++){
        for(int j=-1 ; j<2 ; j++){
            if(i==0 && j==0)continue;
            mov.push_back({i,j});
        }
    }
    
    vector<pair<int,int>> ans;
    while(cin >> x >> y){
        if(x==0 && y==0) break;
        pair<int,int> a=solve(y,x,mov);
        ans.push_back(a);
    }
    
    int maze=0;
    for(int i=0 ; i<ans.size() ; i++){
        maze++;
        cout<<"Maze #"<<maze<<":"<<endl;
        if(ans[i].F>0) cout<<ans[i].F<<" Cycles; the longest has length "<<ans[i].S/2<<".";
        else cout<<"There are no cycles.";
        if(i != ans.size()-1) cout<<"\n"<<endl;
    }
}