#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int INF=1e17;

struct SegTree{
    vector<int> st;
    int N;
    SegTree(){}
    SegTree(vector<int> &a){
        int n=a.size();
        while(__builtin_popcount(n) != 1){
            a.push_back(-INF); n++;
        }
        N=n;
        st.resize(2*n);
        for(int i=0 ; i<n ; i++){
            st[n+i]=a[i];
        }
        for(int i=n-1 ; i>=1 ; i--){
            st[i]=max(st[2*i],st[2*i+1]);
        }
    }
    int query(int node, int l, int r, int query_l, int query_r){
        if(query_l<=l && r<=query_r) return st[node];
        if(r<query_l || query_r<l) return -INF;
        int mid=l+(r-l)/2;
        int left=query(node*2, l, mid, query_l, query_r);
        int right=query(node*2+1, mid+1, r, query_l, query_r);
        return max(left,right);
    }
};

vector<SegTree> sst;

int query(int x1, int y1, int x2, int y2, int n, int m){
    int res = -INF;
    for(x1+=n, x2+=n; x1<=x2; x1/=2, x2/=2){
        if(x1&1) res = max(res, sst[x1++].query(1, 0, sst[x1].N-1, y1, y2));
        if(!(x2&1)) res = max(res, sst[x2--].query(1, 0, sst[x2].N-1, y1, y2));
    }
    return res;
}

void solve(){
    int n,m; cin >> n >> m;
    int tmp_n=n;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
        }
    } 

    while(__builtin_popcount(n) != 1) n++;

    sst.resize(2*n);

    for(int i=0 ; i<tmp_n ; i++){
        sst[n+i]=SegTree(a[i]);
    }
    if(n > tmp_n){
        vector<int> tmp(m,-INF);
        for(int i=tmp_n ; i<n ; i++){
            sst[n+i]=SegTree(tmp);
        }
    }
    for(int i=n-1 ; i>=1 ; i--){
        vector<int> merged(m);
        for(int j=0 ; j<m ; j++){
            merged[j]=max(
                sst[2*i].query(1,0,sst[2*i].N-1,j,j),
                sst[2*i+1].query(1,0,sst[2*i+1].N-1,j,j)
            );
        }
        sst[i]=SegTree(merged);
    }

    int row,col; cin >> row >> col;
    int ans_row=tmp_n-row+1;
    int ans_col=m-col+1;
    for(int i=0 ; i<ans_row ; i++){
        for(int j=0 ; j<ans_col ; j++){
            cout<< query(i,j,i+row-1,j+col-1,n,m) <<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    solve();
}

