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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    if(a[0]>=0 && a[n-1]>=0){
        // jaja
    }else if(a[0] == -1 && a[n-1] == -1){
        a[0]=a[n-1]=0;
    }else{
        if(a[0]==-1) a[0]=a[n-1];
        else a[n-1]=a[0];
    }
    for(int i=1 ; i<n-1 ; i++){
        if(a[i] == -1) a[i]=0;
    }
    cout<< abs(a[0]-a[n-1]) <<"\n";
    for(auto x : a) cout<< x <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}