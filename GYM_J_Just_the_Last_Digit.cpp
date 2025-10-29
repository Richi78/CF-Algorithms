#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define all(v) v.begin(),v.end()

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            char c; cin >> c;
            a[i][j]=c-'0';
        }
    }
    // for(auto x : a){
        // vdebug(x)
    // }    
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i=n-2 ; i>=0 ; i--){
        for(int j=i+1 ; j<n ; j++){
            int sum=0;
            for(int k=i+1 ; k<j ; k++){
                sum=(sum+adj[i][k]*a[k][j])%10;
            }
            int x=(a[i][j]-sum+10)%10;
            if(x!=0)adj[i][j]=1;
        }
    }
    for(auto x : adj){
        for(auto e : x) cout<< e;
        cout<<"\n";
    }
}
signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}
