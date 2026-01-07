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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++){
        cout<< "? " << i << " " << n <<" ";
        for(int j=1 ; j<=n ; j++) cout<< j <<" ";
        cout<<endl;
        int r; cin >> r;
        a[i]=r;
    }
    int mx=0 , idx=-1;
    for(int i=1 ; i<=n ; i++){
        if(a[i] > mx){
            mx=a[i]; idx=i;
        }
    }
    vector<int> ans={idx};
    int cur=idx;
    while(mx > 1){
        for(int i=1 ; i<=n ; i++){
            if(a[i] == mx-1){
                assert(cur != i);
                cout<< "? " << cur << " 2 " << cur << " " << i <<endl;
                int x; cin >> x;
                if(x == 2){
                    ans.push_back(i);
                    cur=i;
                    mx--;
                    break;
                }
            }
        }
    }
    cout<< "! " << ans.size() <<" ";
    for(auto x : ans) cout<< x <<" ";
    cout<<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}