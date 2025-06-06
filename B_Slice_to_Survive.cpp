#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m,a,b; cin >> n >> m >> a >> b;
    
    vector< pair<int,int> > dim={
        {a,m} , {n-a+1,m} , {n,b} , {n,m-b+1}
    };

    int ans=1e9;
    for(auto [x,y] : dim){
        int tmp=0;
        while(x>1){
            tmp++; x=(x+1)/2;
        }
        while(y>1){
            tmp++; y=(y+1)/2;
        }
        ans=min(ans,tmp);
    }
    cout<< 1+ans <<endl;
}

signed main(){
    // FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


