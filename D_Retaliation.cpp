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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin >> a[i];

    if( (2*a[1]-a[2])%(n+1) != 0 ){
        cout<<"NO"<<endl; return;
    } 
    //freq second op
    int y = (2*a[1]-a[2])/(n+1);
    
    // freq first op
    int x = a[1] - y*n;
    
    if(x<0 || y<0){
        cout<<"NO"<<endl; return;
    }

    // debug2(x,y)
    
    for(int i=1 ; i<=n ; i++){
        int z = a[i] - x*i - y*(n-i+1);
        if(z != 0){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}