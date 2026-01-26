#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int N=1<<23;
vector<int> P;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    sort(all(a));
    long long A=0 , PP=0;
    int ans=n;
    for(int i=0 ; i<n ; i++){
        A+=a[n-1-i]; PP+=P[i];
        if(A >= PP) ans=n-1-i;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    vector<bool> a(N,true);
    for(int i=2 ; i<N ; i++){
        if(a[i]){
            P.push_back(i);
            for(int j=i+i ; j<N ; j+=i){
                a[j]=false;
            }
        }
    }
    assert(P.size()>=(int)4e5);
    int tc;cin>>tc;
    while(tc--)solve();
}