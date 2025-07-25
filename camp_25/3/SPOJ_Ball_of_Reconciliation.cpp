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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(int n){
    int cnt=0;
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<=i ; j++){
            int tmp=i*j;
            if(n-tmp < 0) break;
            if( (n-tmp)%(i+j) == 0){
                int k=(n-tmp)/(i+j);
                if(k>j)continue;
                if(tmp+i*k+j*k == n)cnt++;
            }
        }
    }

    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    int n;
    while(cin >> n){
        if(n == -1) break;
        solve(n);
    }
}

