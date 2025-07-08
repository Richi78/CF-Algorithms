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

const int N=1e6+1;
int a[N]={};

void solve(){
    int n; cin >> n;
    
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[x]++;
    }

    for(int i=N ; i>=1 ; i--){
        int tmp=0;
        for(int j=i ; j<=N ; j+=i){
            tmp+=a[j];
        }
        if(tmp>1){
            cout<< i <<"\n"; return;
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}