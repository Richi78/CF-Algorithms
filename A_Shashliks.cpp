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

void solve(){
    int k,a,b,x,y; cin >> k >> a >> b >> x >> y;
    int ans=0;
    if(x<y){
            int tmp=max(0LL,(k - a + x - 1) / x);
            k-=tmp*x;
            if(k >= a){
                k-=x; tmp++;
            }
            int tmp2=max(0LL,(k - b + y - 1) / y);
            k-=tmp2*y;
            if(k >= b){
                k-=y; tmp2++;
            }
            ans+=tmp + tmp2;
       
    }else if(y<x){
        int tmp=max(0LL,(k - b + y - 1) / y);
        k-=tmp*y;
        if(k >= b){
            k-=y; tmp++;
        }
        int tmp2=max(0LL,(k - a + x - 1) / x);
        k-=tmp2*x;
        if(k >= a){
            k-=x; tmp2++;
        }
        ans+=tmp + tmp2; 
    }else{
        if(b<a){
            int tmp=max(0LL,(k - a + x - 1) / x);
            k-=tmp*x;
            if(k >= a){
                k-=x; tmp++;
            }
            int tmp2=max(0LL,(k - b + y - 1) / y);
            k-=tmp2*y;
            if(k >= b){
                k-=y; tmp2++;
            }
            ans+=tmp + tmp2;
        }else{ // b>=a
            int tmp=max(0LL,(k - b + y - 1) / y);
            k-=tmp*y;
            if(k >= b){
                k-=y; tmp++;
            }
            int tmp2=max(0LL,(k - a + x - 1) / x);
            k-=tmp2*x;
            if(k >= a){
                k-=x; tmp2++;
            }
            ans+=tmp + tmp2; 
        }
    }
    cout<< ans << "\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}