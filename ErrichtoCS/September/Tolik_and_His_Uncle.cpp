#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> a(n*m);
    int row=1 , col=1;
    int sz=n*m;
    for(int i=0 ; i<sz ; i++){
        a[i]={row,col};
        col=(col+1)%(m+1);
        if(col == 0){
            col=1;
            row++;
        }
    } 

    int front=0 , back=sz-1;
    for(int i=0 ; i<sz ; i++){
        if(!(i&1)){
            cout<< a[front].first <<" "<< a[front].second <<"\n";
            front++;
        }else{
            cout<< a[back].first <<" "<< a[back].second <<"\n";
            back--;
        }
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}