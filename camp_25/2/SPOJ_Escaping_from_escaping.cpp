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

void solve(){
    string s; cin >> s;

    int n=(int)s.size();
    for(int i=1 ; i<1e5 ; i++){
        set<string> st;
        for(int j=0 ; j+i<=n ; j++){
            st.insert(s.substr(j,i));
        }
        if(st.size() < (1LL<<i)){
            cout<< i <<"\n"; return;
        }
        for(auto x:st){
            cout<< x <<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}