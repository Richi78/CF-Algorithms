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

void solve(){
    int n,x; cin >> n >> x;

    int sz=1LL << n;
    vector<bool> vis(sz);
    vector<int> st;
    for(int i=0 ; i<sz ; i++){
        if(!vis[i]){
            st.push_back(i);
            vis[i]=true;
            if( (i^x) < sz) vis[i^x]=true;
        }
    }

    cout<< st.size()-1 <<"\n";
    for(int i=1 ; i<(int)st.size() ; i++){
        cout<< (st[i]^st[i-1]) <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}