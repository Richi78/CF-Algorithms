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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n; cin >> n;
    vector< pair<int,int> > odd , even;
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        if(x&1) odd.emplace_back(x,i);
        else even.emplace_back(x,i);
    }
   
    int mx=-1;
    for(int i=0 ; i<odd.size() ; i++){
        if(odd[i].F == 1){
            mx=max(mx,odd[i].S*2); 
        }
        for(int j=0 ; j<even.size() ; j++){
            if( gcd(odd[i].F,even[j].F) == 1){
                mx=max(mx,odd[i].S+even[j].S);
            }
        }
    } 
    cout<< mx <<"\n"; 
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}