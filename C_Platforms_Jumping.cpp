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
    int n,m,d; cin >> n >> m >> d;
    vector<int> a(m) , b(n);
    for(int i=0 ; i<m ; i++) cin >> a[i];

    int i=0 , cnt=1;
    auto it=a.begin();
    while(i<n+1){
        i+=d;
        if(it != a.end()){
            int tmp=*it;
            while(tmp){
                // b[i]
            } 
        }

        if(it==a.end())
    }

    cout<<"YES\n";
    for(int i=0 ; i<n ; i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}