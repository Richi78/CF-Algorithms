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
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    bool f=false;
    for(int i=0 ; i<n ; i++){
        if(f && x==0 && a[i]==1){
            cout<<"NO"<<endl; return;
        }else if(f && x){
            x--;
        }else if(f==0 && a[i]==1){
            f=true; x--;
        }
    }
    cout<<"YES"<<endl;
   
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}