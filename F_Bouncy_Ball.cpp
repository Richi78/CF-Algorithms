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

struct Point{
    int x,y;
    Point (int x, int y): x(x),y(y){}
    void DL(){x+=1;y-=1;}
    void DR(){x+=1;y+=1;}
    void UR(){x-=1;y+=1;}
    void UL(){x-=1;y-=1;}
    bool operator==(Point b){return x==b.x && y==b.y;}
};

// bool operator==(Point a, Point b) {return a.x==b.x && a.y==b.y;}

void solve(){
    int n,m,ix,iy,fx,fy; string dir; 
    cin >> n >> m >> ix >> iy >> fx >> fy >> dir;
    Point pos(ix,iy);
    Point meta(fx,fy);

    // vector< vector<int> > vis(n+1, vector<int>(m+1));

    int cnt=0;
    if(pos.x==1&&pos.y==1){dir="DR";cnt++;}
    else if(pos.x==n&&pos.y==1){
        if(dir!="UR")cnt++;
        dir="UR";
    }
    else if(pos.x==1&&pos.y==m){
        if(dir!="DL")cnt++;
        dir="DL";
    }
    else if(pos.x==n&&pos.y==m){
        if(dir!="UL")cnt++;
        dir="UL";
    }
    else if(pos.x==n){
        if(dir=="DL")dir="UL";
        else if(dir=="DR")dir="UR";
        cnt++;
    }else if(pos.x==1){
        if(dir=="UR"){dir="DR";cnt++;}
        else if(dir=="UL"){dir="DL";cnt++;}
    }else if(pos.y==m){
        if(dir=="DR"){dir="DL";cnt++;}
        else if(dir=="UR"){dir="UL";cnt++;}
    }else if(pos.y==1){
        if(dir=="UL"){dir="UR";cnt++;}
        else if(dir=="DL"){dir="DR";cnt++;}
    }

    // while(!vis[pos.x][pos.y]){
    while(1){
        if(pos == meta){
            cout<< cnt <<endl; return; 
        }
        // vis[pos.x][pos.y]=1;
        if(dir=="DL")pos.DL();
        else if(dir=="DR")pos.DR();
        else if(dir=="UR")pos.UR();
        else if(dir=="UL")pos.UL();
        if(pos == meta){
            cout<< cnt <<endl; return; 
        }
        if(pos.x==1&&pos.y==1){cout<<-1<<endl;return;}//dir="DR";
        else if(pos.x==n&&pos.y==1){cout<<-1<<endl;return;}//dir="UR";
        else if(pos.x==1&&pos.y==m){cout<<-1<<endl;return;}//dir="DL";
        else if(pos.x==n&&pos.y==m){cout<<-1<<endl;return;}//dir="UL";
        else if(pos.x==n){
            if(dir=="DL")dir="UL";
            else if(dir=="DR")dir="UR";
            cnt++;
        }else if(pos.x==1){
            if(dir=="UR")dir="DR";
            else if(dir=="UL")dir="DL";
            cnt++;
        }else if(pos.y==m){
            if(dir=="DR")dir="DL";
            else if(dir=="UR")dir="UL";
            cnt++;
        }else if(pos.y==1){
            if(dir=="UL")dir="UR";
            else if(dir=="DL")dir="DR";
            cnt++;
        }
    }
    // for(auto x : vis){
    //     vdebug(x)
    // }
    // cout<<-1<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}