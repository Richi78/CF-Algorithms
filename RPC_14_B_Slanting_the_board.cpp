#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

int n,m;
int sz;

int getState(vector<vector<char>> &a){
    int ans=0;
    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            if(a[row][col] == 'X'){
                ans|=(1LL<<(row*m+col));
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
                ans|=(1LL<<(row*m+col));
            }
        }
    }
    return ans;
}

int opButtom(int mask, int wall){
    int ans=mask;
    for(int row=n-1 ; row>=0 ; row--)
    for(int col=0 ; col<m ; col++){
        int pos=row*m+col;
        int x=1LL<<pos;
        if(ans & x){
            int tmp=1;
            while( row+tmp<n 
                && !( wall & (1LL<<( (row+tmp)*m + col )) ) 
                && !( ans & (1LL<<( (row+tmp)*m +col )) ) ) tmp++;
            tmp--;
            ans&= ~x; 
            ans|=(1LL<<( (row+tmp)*m + col ));
        }
    }
    return ans;
}

int opLeft(int mask, int wall){
    int ans=mask;
    for(int col=0 ; col<m ; col++)
    for(int row=0 ; row<n ; row++){
        int pos=row*m+col;
        int x=1LL<<pos;
        if(ans & x){
            int tmp=1;
            while( (col-tmp)>=0 
                && !( wall & (1LL<<(pos-tmp)) ) 
                && !( ans & (1LL<<(pos-tmp)) ) ) tmp++;
            tmp--;
            ans&= ~x;
            ans|=(1LL<<(pos-tmp));
        }
    }
    return ans;
}

int opRight(int mask, int wall){
    int ans=mask;
    for(int col=m-1 ; col>=0 ; col--)
    for(int row=0 ; row<n ; row++){
        int pos=row*m+col;
        int x=1LL<<pos;
        if(ans & x){
            int tmp=1;
            while( (col+tmp)<m 
                && !( wall & (1LL<<(pos+tmp)) ) 
                && !( ans & (1LL<<(pos+tmp)) ) ) tmp++;
            tmp--;
            ans&= ~x;
            ans|=(1LL<<(pos+tmp));
        }
    }
    return ans;
}

int opTop(int mask, int wall){
    int ans=mask;
    for(int row=0 ; row<n ; row++)
    for(int col=0 ; col<m ; col++){
        int pos=row*m+col;
        int x=1LL<<pos;
        if(ans & x){
            int tmp=1;
            while( row-tmp>=0 
                && !( wall & (1LL<<( (row-tmp)*m + col )) ) 
                && !( ans & (1LL<<( (row-tmp)*m +col )) ) ) tmp++;
            tmp--;
            ans&= ~x; 
            ans|=(1LL<<( (row-tmp)*m + col ));
        }
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    sz=n*m;
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

    int mask_wall=getWall(ini);
    int mask_ini=getState(ini);
    int mask_fin=getState(fin);

    map<int,int> mp;
    queue<int> q;
    q.push(mask_ini);
    mp[mask_ini]++;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node == mask_fin){
            cout<<"YES\n"; return;
        }
        int t=opTop(node,mask_wall);
        if(mp.find(t) == mp.end()){
            mp[t]++;
            q.push(t);
        }
        int l=opLeft(node,mask_wall);
        if(mp.find(l) == mp.end()){
            mp[l]++;
            q.push(l);
        }
        int r=opRight(node,mask_wall);
        if(mp.find(r) == mp.end()){
            mp[r]++;
            q.push(r);
        }
        int b=opButtom(node,mask_wall);
        if(mp.find(b) == mp.end()){
            mp[b]++;
            q.push(b);
        }
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