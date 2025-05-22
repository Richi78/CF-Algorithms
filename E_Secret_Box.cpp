#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int x,y,z,k; cin >> x >> y >> z >> k;
    int ans=0;
    for(int a=1 ; a<=x ; a++){
        for(int b=1 ; b<=y ; b++){
            if(k % (a*b)) continue;
            int c = k / (a*b);
            if(c > z) continue;
            int tmp = (x-a+1) * (y-b+1) * (z-c+1);
            ans=max(ans,tmp); 
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


