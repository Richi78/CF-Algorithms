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

const int N=1e6+5;
int mp[N]={};

void solve(){
    int n; cin >> n;
    int tmp=n;
    if(mp[n] != 0){
        cout<<mp[n]<<"\n"; return;
    }
    int ans=1;
    for(int i=2 ; i*i<=n ; i++){
        if(n%i == 0){
            int cnt=0;
            while(n%i == 0){
                cnt++; n/=i;
            }
            ans*=(cnt+1);
        }
    }

    if(n != 1) ans*=2;
    mp[tmp]=ans;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}