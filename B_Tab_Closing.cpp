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
    int a,b,n; cin >> a >> b >> n;

    if(b <= 1.0*a/n || a<=b){
        cout<< "1\n"; return;
    }else{
        cout<< "2\n"; return;
    }

    // int ans=1e18;
    // int cur2=0; //left
    // for(int m=n ; m>=1 ; m--){
    //     long double x=1.0*a/m;
    //     long double tmp=min(1.0L*b , x);
    //     if(tmp == b){
    //         cur2++; break;
    //     }else{
    //         cur2++;
    //     }
    // }

    // // debug1(cur2)

    // int cur1=1; //right
    // for(int m=n ; m>=1 ; m--){
    //     long double x=1.0*a/m;
    //     long double tmp=min(1.0L*b , x);
    //     if(tmp == b){
    //         if(tmp*m == n){
    //             // considerar m-1
    //             cur1+=m-1;   
    //         }else{
    //             // cosiderar m
    //             cur1+=m;
    //         }
    //         break;
    //     }
    // }
    // int x=min(cur1,cur2);
    // cout<< (x>=2?2:1) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}