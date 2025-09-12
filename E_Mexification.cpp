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

void doOp(vector<int> &a, int n){
    vector<int> freq(n+1);
    for(int i=0 ; i<n ; i++) freq[a[i]]++;
    int mex=0;
    for(int i=0 ; i<=n ; i++){
        if(freq[i] == 0){
            mex=i; break;
        }
    }
    // debug1(mex)
    for(int i=0 ; i<n ; i++){
        if(a[i] > mex || freq[a[i]]-1>0) a[i]=mex;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    doOp(a,n); k--;
    if(k>1){
        doOp(a,n);
        k--;
    } 
    if(k&1) doOp(a,n);

    cout<< accumulate(all(a), 0LL) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}