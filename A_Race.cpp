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
    int a,x,y; cin >> a >> x >>y;

    int a1=abs(a-x) , a2=abs(a-y);
    
    for(int i=1 ; i<=100 ; i++){
        if(i != a){
            int b1=abs(i-x) , b2=abs(i-y);
            if( (b1<a1) && (b2<a2) ){
                cout<<"YES\n"; return;
            }
        }
    }
    cout<<"NO\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}