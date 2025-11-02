
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

    int A=a[0]/3;
    int C=a[n-1]/3;

    for(int b=A+1 ; b<C ; b++){
        bool ok=true;
        for(int i=0 ; i<n && ok; i++){
            bool tmp=false;
            tmp|=(3*A==a[i]);
            tmp|=(3*b==a[i]);
            tmp|=(3*C==a[i]);
            tmp|=(2*A+b)==a[i];
            tmp|=(2*A+C)==a[i];
            tmp|=(2*b+A)==a[i];
            tmp|=(2*b+C)==a[i];
            tmp|=(2*C+A)==a[i];
            tmp|=(2*C+b)==a[i];
            tmp|=(A+b+C)==a[i];
            ok&=tmp;
        } 
        if(ok){
            cout<< A <<" "<< b <<" "<< C <<"\n";
            return;
        }
    }
    cout<<"xd";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}
