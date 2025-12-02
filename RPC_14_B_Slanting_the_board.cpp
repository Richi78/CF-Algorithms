#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int getState(vector<vector<char>> &a){
    int ans=0;
    int n=a.size() , m=a[0].size();
    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            if(a[row][col] == 'X'){
                ans|=(1LL<<(row*n+col));
            }
        }
    }
    return ans;
}

int getWall(vector<vector<char>> &a){
    int ans=0;
    int n=a.size() , m=a[0].size();
    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            if(a[row][col] == '#'){
                ans|=(1LL<<(row*n+col));
            }
        }
    }
    return ans;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<char>> ini(n,vector<char>(m,' '));
    vector<vector<char>> fin(n,vector<char>(m,' '));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> ini[i][j];
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> fin[i][j];
        }
    }

    int mask_wall=getState(ini);
    int mask_ini=getState(ini);
    int mask_fin=getState(fin);
    debug2(mask_ini,mask_fin)

    map<int,int> mp;
    queue<int> q;
    q.push(mask_ini);
    mp[mask_ini]++;
    while(!q.empty()){
        int node=q.front();
        q.pop();

    }
    cout<<"NO\n"; 
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}