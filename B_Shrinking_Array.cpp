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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    if(n == 2){
        if(abs(a[0]-a[1]) <= 1) cout<<"0\n";
        else cout<<"-1\n";
        return;
    }

    bool z=false , o=false;
    for(int i=0 ; i<n ; i++){
        if( i+1<n && abs(a[i]-a[i+1]) <= 1 ){
            z=true; 
        }   
        if(i+2<n){
            if( min(a[i],a[i+1])<=a[i+2] && a[i+2]<=max(a[i],a[i+1]) ){
                o=true;
            }
            if( min(a[i+1],a[i+2])<=a[i] && a[i]<=max(a[i+1],a[i+2]) ){
                o=true;
            }
        }
    } 
    if(z) cout<<"0\n";
    else if(o) cout<<"1\n";
    else cout<<"-1\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}