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

// corregir a una version con dp bottom up y directo devolver el resultado
int f(int n, int row, map<int,int> &dp){
    // debug2(n,row)
    if( dp[n] ) return 0;
    if(row == 1) return 1;
    int tmp=(row*(row-1))/2;
    int l=0 , r=0;
    if(n-row >= tmp-row+2){
        l=f(n-row , row-1, dp);
        dp[n-row]=l;
    }
    if(n-row+1 <= tmp){
        r=f(n-row+1, row-1, dp);
        dp[n-row+1]=r;
    } 
    return dp[n]=n*n + l + r;
}

void solve(){
    int n; cin >> n;

    int i=1e9;
    int l=0 , r=1e4;
    while(l <= r){
        int mid=(l+r)/2;
        int tmp=(mid*(mid+1))/2;
        if(n<=tmp){
            i=min(i,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    map<int,int> dp;
    int ans =f(n,i,dp);

    cout<< ans <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}