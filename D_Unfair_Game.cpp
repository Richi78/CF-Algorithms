#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int N=32;
vector<vector<int>> C(N,vector<int>(N));

void solve(){
    int n,k; cin >> n >> k;
    int msb=0;
    while(n) msb++ , n>>=1;
    int ans=0;
    if(msb > k) ans++;
    for(int i=1 ; i<msb ; i++){
        for(int j=0 ; j<i ; j++){
            if(i+j > k){
                ans+=C[i-1][j]; 
            } 
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    for(int i=0 ; i<N ; i++){
        C[i][0]=C[i][i]=1;
        for(int j=1 ; j<i ; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    } 
    int tc;cin>>tc;
    while(tc--)solve();
}