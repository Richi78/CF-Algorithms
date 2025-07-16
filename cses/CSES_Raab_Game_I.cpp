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
    int n,x,y; cin >> n >> x >> y;
   
    if(x == 0 && y == 0){
        cout<<"YES\n";
        for(int i=1 ; i<=n ; i++) cout<<i<<" "; 
        cout<<"\n";
        for(int i=1 ; i<=n ; i++) cout<<i<<" "; 
        cout<<"\n";
    }else if( (x==0&&y!=0) || (x!=0&&y==0) || x+y>n ){
        cout<<"NO\n";
    }else{
        int tie=n-x-y;
        n-=tie;
        cout<<"YES\n";
        for(int i=1 ; i<=n ; i++) cout<<i<<" "; 
        for(int i=n+1 ; i<=n+tie ; i++) cout<<i<<" ";
        cout<<"\n";
        for(int i=1 ; i<=n ; i++) {
            int z=i+x;
            if(z>n){
                z-=n;
            }
            cout<< z <<" ";
        }
        for(int i=n+1 ; i<=n+tie ; i++) cout<<i<<" ";
        cout<<"\n";
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}