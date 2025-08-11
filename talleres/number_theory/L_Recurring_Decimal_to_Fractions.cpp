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

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(){
    int a,b; cin >> a >> b;
    string x,y; cin >> x >> y;
   
    int num=stoll(x+y);
    num -= stoll(x);
    int dem = binexp(10,a) * ( binexp(10,b) - 1 );

    int g=gcd(num,dem);
    while(g!=1){
        while(num%g==0 && dem%g==0){
            num/=g; dem/=g;
        }
        g=gcd(num,dem);
    }
    cout<<num<<" "<<dem<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}