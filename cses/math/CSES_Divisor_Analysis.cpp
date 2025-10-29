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

const int MOD=1e9+7;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    // #div , SumDiv , ProdDiv
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        a[i]={x,y};
    }
    int d=1;
    for(int i=0 ; i<n ; i++){
        d=(d*(a[i].second+1))%MOD;
    }

    int s=1;
    for(int i=0 ; i<n ; i++){
        s=(s*(binexp(a[i].first , a[i].second+1) - 1 +MOD ))%MOD;
        s=(s*(binexp(a[i].first-1 , MOD-2)))%MOD;
    }

    bool odd=false;
    int odd_pos=-1;
    for(int i=0 ; i<n ; i++){
        if(a[i].second&1){
            odd=true;
            odd_pos=i;
            break;
        }
    }

    int new_d=1;
    int p=1;
    if(odd){
        for(int i=0 ; i<n ; i++){
            if(i == odd_pos){
                new_d=(new_d*(a[i].second+1)/2)%(MOD-1);
            }else{
                new_d=(new_d*(a[i].second+1))%(MOD-1);
            }
        }
        for(auto [x,y] : a){
            p=(p*binexp(x, (y*new_d)%(MOD-1)))%MOD;
        }
    }else{
        for(int i=0 ; i<n ; i++){
            new_d=(new_d*(a[i].second+1))%(MOD-1);
        }
        for(auto [x,y] : a){
            p=(p*binexp(x, (y/2*new_d)%(MOD-1)))%MOD;
        }
    }

    cout<< d <<" "<< s <<" "<< p <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}