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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n; cin >> n;
    vector<int> a(1001);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        a[x]=i;
    }

    // for(int i=0 ; i<8 ; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    int mx=-1;
    for(int i=1 ; i<=1000 ; i++){
        for(int j=1 ; j<=1000 ; j++){
            if( a[i] && a[j] && gcd(i,j) == 1 ){
                mx=max(mx,a[i]+a[j]);
            }
        }
    }
    cout<< mx <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}