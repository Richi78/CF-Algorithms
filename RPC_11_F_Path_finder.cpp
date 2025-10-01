#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int dist(int a, int b, int c, int d){
    return abs(a-c)+abs(b-d);
}

vector<pair<int,int>> moves={
    {0,1} , {0,-1}, {1,0} , {-1,0}
};

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,1e18));
    vector<vector<bool>> vis(n,vector<bool>(m));
    // vector<pair<int,int>> w;
    set<array<int,3>> st;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            char c; cin >> c;
            if(c=='W'){
                a[i][j]=0;
                st.insert({0,i,j});
                vis[i][j]=true;
            }
        }
    }

    while(!st.empty()){
        auto it=*st.begin();
        st.erase(st.begin());
        int d=it[0] , r=it[1] , c=it[2];
        for(auto [x,y] : moves){
            int nr=r+x , nc=c+y;
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(d+1<a[nr][nc]){
                    if(a[nr][nc] != 1e18){
                        st.erase({a[nr][nc],nr,nc});
                    }
                    a[nr][nc]=d+1;
                    st.insert({d+1,nr,nc});
                }
            }
        }
    }

    int mn=1e18;
    st.insert({a[0][0],0,0});
    vis[0][0]=true;
    while(!st.empty()){
        auto it=prev(st.end());
        st.erase(it);
        int d=(*it)[0] , r=(*it)[1] , c=(*it)[2];
        mn=min(mn,d);
        if(r==n-1 && c==m-1) break;
        for(auto [x,y] : moves){
            int nr=r+x , nc=c+y;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                st.insert({a[nr][nc],nr,nc});
                vis[nr][nc]=true;
            }
        }
    }
    cout<< mn <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}