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
    int n; cin >> n;
    vector<int> a(n+1);
    int x=1 , odd=1 , even=n;
    bool turn=1; // 1 odd 0 even
    while(1){
        if(turn){
            if(a[odd]!=0)break;
            a[odd]=x; 
            x++;
            odd++;
        }else{
            if(a[even]!=0)break;
            a[even]=x;
            x++;
            even--;
        }
        turn=!turn;
    }
    for(int i=1; i<=n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}