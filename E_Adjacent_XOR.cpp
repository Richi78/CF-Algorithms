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

void solve(){
    int n; cin >> n;
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> b[i];

    if(a.back() != b.back()){
        cout<< "NO\n"; return;
    }
    
    vector<bool> vis(n);
    int equal=1;
    while(true){
        bool change=false;
        for(int i=0 ; i+1<n ; i++){
            if(a[i] == b[i]){
                continue;
            } 
            if(!vis[i]){
                if((a[i] ^ a[i+1]) == b[i]){
                    a[i]^=a[i+1];
                    vis[i]=true;
                    change=true;
                    continue;
                }
            }
        }
        if(!change){
            // cout<<"NO\n"; return;
            break;
        }
    }
    for(int i=0 ; i<n ; i++){
        if(a[i] != b[i]){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}


