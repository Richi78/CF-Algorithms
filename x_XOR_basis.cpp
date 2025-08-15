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

struct Basis{
    int d=64;
    vector<int> basis; // basis[ i ] keeps the mask of the vector whose f is value 1
    int sz=0; // current size of the basis
    Basis(){
        basis.resize(d);
    }
    void insertVector(int mask){
        for(int i=d-1 ; i>=0 ; i--){
            if( (mask & (1LL<<i)) == 0 ) continue; // continue if i != f(mask)
            if( !basis[i] ){  // if there is no basis vector with the i-th bit set, then insert this vector into the basis
                basis[i]=mask;
                ++sz;
                return;
            }
            mask ^= basis[i]; // otherwise subtract the basis vector from this vector
        }
    }
};

void solve(){
    Basis b;
    b.insertVector(1);
    b.insertVector(5);
    b.insertVector(8);
    b.insertVector(14);
    b.insertVector(15);
    b.insertVector(13);
    b.insertVector(12);
    b.insertVector(11);
    vdebug(b.basis)
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}


