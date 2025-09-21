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


int getDist(int a, int b, int c, int d){
    return abs(a-c)+abs(b-d);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n-1);
    int x,y; cin >> x >> y;
    int last_x=x, last_y=y;
    for(int i=0 ; i<n-1 ; i++){
        cin >> x >> y;
        a[i]=getDist(last_x,last_y,x,y);
        last_x=x; last_y=y;
    }

    vector<int> pref(n);
    pref[0]=0;
    for(int i=1 ; i<n-1 ; i++){
        if(i&1) pref[i] = pref[i-1] + a[i-1];
        else pref[i] = pref[i-1] - a[i-1];
    }

    // vdebug(a)
    // vdebug(pref)

    int lb=1 , ub=1e18;
    for(int i=0 ; i<n-1 ; i++){
        if(i&1){
            lb=max(lb,pref[i]-a[i]+1);
            ub=min(ub,pref[i]-1);
        }else{
            lb=max(lb, pref[i]+1);
            ub=min(ub, pref[i]+a[i]-1);
        }
    }
    if(lb > ub){
        cout<<"-1\n";
    }else{
        cout<< ub <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}