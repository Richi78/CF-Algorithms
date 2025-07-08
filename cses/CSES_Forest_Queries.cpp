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

void solve(){
    int n,m; cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(n));
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        for(int j=0 ; j<n ; j++){
            if(s[j] == '.') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    
    vector< vector<int> > pref(n+1, vector<int>(n+1));
    pref[1][1]=a[0][0];
    for(int i=2 ; i<=n ; i++) pref[1][i]=a[0][i-1]+pref[1][i-1];
    for(int i=2 ; i<=n ; i++) pref[i][1]=a[i-1][0]+pref[i-1][1];
    for(int i=2 ; i<=n ; i++){
        for(int j=2 ; j<=n ; j++){
            pref[i][j]=a[i-1][j-1]+pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
        }
    }

    for(int i=0 ; i<m ; i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans=pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}