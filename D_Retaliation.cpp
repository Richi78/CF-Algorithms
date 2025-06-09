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
    bool f= a[0]>a[1] ? 0 : 1; //0 decrece 1 crece
    for(int i=1 ; i<n ; i++){
        if(f==0){
            if(a[i-1] <= a[i]){
                cout<<"NO"<<endl; return;
            }
        }else{
            if(a[i-1] >= a[i]){
                cout<<"NO"<<endl; return;
            }
        }
    }
    for(int i=0 ; i+1<n ; i++){
        bool ok=false;
        int x=a[i]-(i+1) , y=a[i+1]-(i+1+1);
        debug2(x,y)
        if(x%y==0 || y%x==0){
            ok=true;continue;
        }
        int z=a[i]-(n)-(i+1)+1 , w=a[i+1]-n-(i+1+1)+1;
        debug2(z,w)
        if(z%w==0 || w%z==0){
            ok=true; continue;
        }
        cout<<"NO"<<endl; return;
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}