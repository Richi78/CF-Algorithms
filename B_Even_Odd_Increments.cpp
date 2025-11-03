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
    int n,q; cin >> n >> q;

    vector<int> a(n);
    int e=0 , o=0;
    int sum_e=0 , sum_o=0;
    for(int i=0 ; i<n ; i++){
        cin >>a[i];
        if(a[i]&1) o++, sum_o+=a[i];
        else e++, sum_e+=a[i];
    }

    for(int rep=0 ; rep<q ; rep++){
        int t,x; cin >> t >> x;
        if(t){
            // add to odd's
            if(x&1){
                int tmp=o*x;
                sum_e+=sum_o+tmp;
                sum_o=0;
                e+=o;
                o=0;
            }else{
                sum_o+=o*x;
            }
            cout<< sum_e+sum_o <<"\n";
        }else{
            // add even
            if(x&1){
                int tmp=e*x;
                sum_o+=sum_e+tmp;
                sum_e=0;
                o+=e;
                e=0;
            }else{
                sum_e+=e*x;
            }
            cout<< sum_e+sum_o <<"\n";
        }
        // debug2(sum_o,sum_e)
        // debug2(o,e)
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}