#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n,x; cin >> n >> x;
    vector<char> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    if(x == 1 || x == n){
        cout<< 1 <<"\n"; return;
    }
    int left=-1e8 , right=1e8;
    for(int i=1 ; i<=n ; i++){
        if(i<x && a[i]=='#') left=i;
        if(i>x && a[i]=='#'){
            right=i; break;
        }
    }
    if(left == -1e8 && right == 1e8){
        cout<< "1\n"; 
    }else{
        cout<< max(min(x, n-right+2) , min(left+1 , n-x+1)) <<"\n";
    }
        
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}