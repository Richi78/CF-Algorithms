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

const int INF=1e18;
vector<vector<int>> st;
int N,M;

int query_y(int node_x, int node, int l, int r, int query_l, int query_r){
    if(query_l<=l && r<=query_r) return st[node_x][node];
    if(r<query_l || query_r<l) return -INF;
    int mid=l+(r-l)/2;
    int left=query_y(node_x, node*2, l, mid, query_l, query_r);
    int right=query_y(node_x, node*2+1, mid+1, r, query_l, query_r);
    return max(left, right);
}

int query_x(int node, int l, int r, int x1, int y1, int x2, int y2){
    if(x1<=l && r<=x2){
        return query_y(node, 1, 0, M-1, y1, y2);
    }
    if(r<x1 || x2<l) return -INF;
    int mid=l+(r-l)/2;
    int left=query_x(node*2, l, mid, x1,y1,x2,y2);
    int right=query_x(node*2+1, mid+1, r, x1,y1,x2,y2);
    return max(left,right);
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            cin >> a[i][j];
    
    N=n; M=m;
    while(__builtin_popcount(N) != 1) N++;
    while(__builtin_popcount(M) != 1) M++;

    st=vector<vector<int>>(2*N, vector<int>(2*M,-INF));
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            st[N+i][M+j]=a[i][j];
    
    for(int col=0 ; col<M ; col++){
        for(int row=N-1 ; row>=1 ; row--){
            st[row][M+col]=max(st[2*row][M+col],st[2*row+1][M+col]);
        }
    }

    for(int row=1 ; row<2*N ; row++){
        for(int col=M-1 ; col>=1 ; col--){
            st[row][col]=max(st[row][2*col],st[row][2*col+1]);
        }
    }

    int row,col; cin >> row >> col;
    int n_row=n-row+1 , n_col=m-col+1;
    for(int i=0 ; i<n_row ; i++){
        for(int j=0 ; j<n_col ; j++){
            cout<< query_x(1,0,N-1,i,j,i+row-1,j+col-1);
            cout<< (j==n_col-1?"":" ");
        }
        cout<<"\n";
    }
    // cout<< query_x(1, 0, N-1, 0,0,1,2) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}