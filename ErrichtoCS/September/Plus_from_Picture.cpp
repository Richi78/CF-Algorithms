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

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<bool>> a(n,vector<bool>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            char c; cin >> c;
            if(c == '*') a[i][j]=true;
        }
    } 

    int x=-1, y=-1;
    bool ok=true;
    for(int i=1 ; i+1<n && ok ; i++){
        for(int j=1 ; j+1<m && ok ; j++){
            if(a[i][j] && a[i+1][j] && a[i-1][j] && a[i][j+1] && a[i][j-1]){
                x=i; y=j; ok=false; 
                break;
            }
        }
    }
    if(x==-1 && y==-1){
        cout<<"NO\n"; return;
    }
    vector<vector<bool>> vis(n,vector<bool>(m));
    vis[x][y]=true;
    for(int i=x+1 ; i<n ; i++){
        if(a[i][y]) vis[i][y]=true;
        else break;
    }
    for(int i=x-1 ; i>=0 ; i--){
        if(a[i][y]) vis[i][y]=true;
        else break;
    }
    for(int i=y+1 ; i<m ; i++){
        if(a[x][i]) vis[x][i]=true;
        else break;
    }
    for(int i=y-1 ; i>=0 ; i--){
        if(a[x][i]) vis[x][i]=true;
        else break;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j] && !vis[i][j]){
                cout<<"NO\n"; return;
            }
        }
    }
    cout<<"YES\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}