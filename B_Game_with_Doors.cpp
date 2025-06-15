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
    int l,r,L,R; cin >> l >> r >> L >> R;
    int ir=min(r,R) , il=max(l,L) , cnt=0;
    if(il > ir){
        cout<<"1\n";
    }else{
        if(ir>=il) cnt+=ir-il;
        if( min(l,L) < il ) cnt++;
        if( max(r,R) > ir ) cnt++;
        cout<< cnt <<"\n";
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}