#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

vector<int> p(20,1);

void solve(){
    int n; cin >> n;

    set<int> st;

    for(int i=1 ; i<18 ; i++){
        int x=1+p[i];
        int y=n/x;
        if(n%x == 0 && y*(1+p[i])==n){
            st.insert(y);
        }
    } 

    cout<< st.size() <<"\n";
    if(st.size()){
        for(auto x : st) cout<< x <<" ";
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;

    for(int i=1 ; i<20 ; i++){
        p[i]=p[i-1]*10;
    }

    while(tc--)solve();
}