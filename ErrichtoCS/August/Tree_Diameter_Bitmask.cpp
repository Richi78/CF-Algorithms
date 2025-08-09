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

int query(vector<int> &a, vector<int> &b){
    cout<< a.size() <<" "<< b.size() <<" ";
    for(int i=0 ; i<(int)a.size() ; i++) cout<< a[i] <<" ";
    for(int i=0 ; i<(int)b.size() ; i++) cout<< b[i] <<" ";
    cout<<endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    int ans=0;
    for(int bit=0 ; bit<7 ; bit++){
        vector<int> a,b;
        for(int i=1 ; i<=n ; i++){
            if((i>>bit) & 1) a.push_back(i);
            else b.push_back(i);
        }
        if(a.size() && b.size()){
            ans=max(ans,query(a,b));
        }
    } 
    cout<< "-1 " << ans <<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}