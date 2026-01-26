#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n,-1));
    int x=n*n-1;
    int i=0 , j=0;
    while(x>=0){
        while(a[i][j]!=-1) j++;
        // R
        while(j<n && a[i][j]==-1 && x>=0) a[i][j]=x-- , j++;
        j--;
        // D
        i++;
        while(i<n && a[i][j]==-1 && x>=0) a[i][j]=x-- , i++;
        i--;
        // L
        j--;
        while(j>=0 && a[i][j]==-1 && x>=0) a[i][j]=x-- , j--;
        j++;
        // U
        i--;
        while(i>=0 && a[i][j]==-1 && x>=0) a[i][j]=x-- , i--;
        i++;
    }
    for(auto f : a){
        for(auto e : f) cout<< e <<" ";
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}