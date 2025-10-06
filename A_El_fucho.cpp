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
    int w=n , l=0;
    int cnt=0;
    while(true){
        int cp_w=w , cp_l=l;
        if(w==1 && l==1){
            break;
        }
        // w group
        int tmp=0;
        if(w&1) tmp=1,w--;
        cnt+=w/2;
        w=(w/2)+tmp;
        // debug1(w)
        
        // l group
        int tmp2=0;
        if(l){
            if(l&1) tmp2=1,l--;
            cnt+=l/2;
            l=(l/2)+tmp2; 
        }
        l+=cp_w/2;
        // debug1(l)
        // debug1(cnt)
    }
    cnt++;
    cout << cnt <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}