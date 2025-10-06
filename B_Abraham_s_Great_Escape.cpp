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
    int n,k; cin >> n >> k;
    if((n*n)-k == 1){
        cout<< "NO\n"; return;
    }
    vector<vector<char>> a(n,vector<char>(n,' '));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(k){
                a[i][j]='U';
                k--;
            }else{
                if(i==n-1){
                    if(j!=n-1){
                        a[i][j]='R';
                    }else{
                        a[i][j]='L';
                    }
                }else{
                    a[i][j]='D';
                } 
            }
        }
    }
    cout<<"YES\n";
    for(auto x : a){
        for(auto y : x){
            cout<< y;
        }
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