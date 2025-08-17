
#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int INF=1e17;
vector<vector<int>> st;

int query(int x1, int y1, int x2, int y2, int N, int M){
    int res = -INF;
    for(x1 += N, x2 += N; x1 <= x2; x1 /= 2, x2 /= 2) {
        int l = y1+M, r = y2+M;
        if(x1 % 2 == 1) {
            int L = l, R = r;
            while(L <= R) {
                if(L % 2 == 1) res = max(res, st[x1][L++]);
                if(R % 2 == 0) res = max(res, st[x1][R--]);
                L /= 2; R /= 2;
            }
            x1++;
        }
        if(x2 % 2 == 0) {
            int L = l, R = r;
            while(L <= R) {
                if(L % 2 == 1) res = max(res, st[x2][L++]);
                if(R % 2 == 0) res = max(res, st[x2][R--]);
                L /= 2; R /= 2;
            }
            x2--;
        }
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

    int N=n , M=m;
    while(__builtin_popcount(N) != 1) N++;
    while(__builtin_popcount(M) != 1) M++;

    st=vector<vector<int>>(2*N,vector<int>(2*M,-INF));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            st[N+i][M+j]=a[i][j];
        }
    }

    for(int i=0 ; i<2*N ; i++){
        for(int j=M-1 ; j>=1 ; j--){
            st[i][j]=max(st[i][2*j],st[i][2*j+1]);
        }
    }

    for(int i=N-1 ; i>=1 ; i--){
        for(int j=1 ; j<2*M ; j++){
            st[i][j]=max(st[2*i][j],st[2*i+1][j]);
        }
    }

    int row,col; cin >> row >> col;
    int ans_row=tmp_n-row+1;
    int ans_col=m-col+1;
    for(int i=0 ; i<ans_row ; i++){
        for(int j=0 ; j<ans_col ; j++){
            cout<< query(i,j,i+row-1,j+col-1,N,M);
            cout<< (j==ans_col-1?"":" ");
        }
        // cout<< (i==ans_row-1?"":"\n");
        cout<<"\n";
    }
}

signed main(){
    FIO;
    solve();
}

