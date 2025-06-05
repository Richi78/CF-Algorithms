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
    int w,b; cin >> w >> b;
    int x=max(w,b);
    int l=0 , r=w+b;
    int k=-1;
    while(l<r){
        int mid=(l+r)/2;
        int tmp=(mid*(mid+1))/2;
        if(x >= tmp/2){
            k=max(k,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<< k <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}