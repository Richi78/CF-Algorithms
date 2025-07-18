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

// alfabet 26
const int A=31;
const int MOD=1e9+7;
vector<int> p;

int getHash(vector<int> &hash, int l, int r){
    int ans = (hash[r] - (hash[l-1]*p[r-l+1]));
    return (ans%MOD + MOD)%MOD;
}

void solve(){
    string s="abcdefg";
    int n=(int)s.size();
    p.resize(n+1,1);
    for(int i=1 ; i<=n ; i++){
        p[i] = (p[i-1] * A) % MOD; 
    }

    vdebug(p)

    vector<int> hash(n+1);

    for(int i=1 ; i<=n ; i++){
        hash[i]= ((hash[i-1]*A)%MOD + s[i-1])%MOD;
    }

    vdebug(hash)

    int x=getHash(hash, 3, 5);

    debug1(x)

    int y='c';
    debug1(y)
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}