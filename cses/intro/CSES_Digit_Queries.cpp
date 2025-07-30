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
    int k; cin >> k;
    int mult=1 , cnt=1;
    int acc=0;
    while(true){
        int skip=9*mult;
        if(k-skip*cnt > 0){
            k-=skip*cnt;
            acc+=skip;
        }else{
            skip=(k-1)/cnt;
            k-=skip*cnt;
            acc+=skip;
            cout<< to_string(acc+1)[k-1] <<"\n";
            return;
        }
        mult*=10; cnt++;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}