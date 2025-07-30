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

vector<string> f(int n){
    if(n == 1){
        return {"0","1"};
    }
    vector<string> tmp=f(n-1);
    vector<string> tmp2=tmp;
    reverse(all(tmp2));
    int sz=tmp.size();
    for(int i=0 ; i<sz ; i++){
        tmp[i]+='0';
        tmp2[i]+='1';
    }
    tmp.insert(tmp.end(), all(tmp2));
    return tmp;
}

void solve(){
    int n; cin >> n;
    vector<string> ans=f(n);

    for(auto x : ans){
        cout<< x <<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}