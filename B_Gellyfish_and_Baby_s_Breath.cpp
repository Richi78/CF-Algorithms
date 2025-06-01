#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int MOD=998244353;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a = (a*a)% MOD;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n) , q(n) , pn(n) , qn(n);
    int mxp=-1 , mxq=-1;
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
        if(uax(mxp,p[i])) pn[i]=i;
        else pn[i]=pn[i-1];
    } 
    for(int i=0 ; i<n ; i++){
        cin >> q[i];
        if(uax(mxq,q[i])) qn[i]=i;
        else qn[i]=qn[i-1];
    } 
    for(int i=0 ; i<n ; i++){
        int x=pn[i] , y=qn[i] , r;
        if(p[x] > q[y]){
            r= (binexp(2,p[x]) + binexp(2,q[i-x]))%MOD;
        }else if(p[x] < q[y]){
            r= (binexp(2,q[y]) + binexp(2,p[i-y]))%MOD;
        }else{ // ==
            int tmp=p[x]+q[i-x] , tmp2=q[y]+p[i-y];
            if(tmp>tmp2){
                r= (binexp(2,p[x]) + binexp(2,q[i-x]))%MOD;
            }else{
                r= (binexp(2,q[y]) + binexp(2,p[i-y]))%MOD;
            }
        }
        cout<<r<<" ";
    }  
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}