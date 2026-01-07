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
    int n,k,l,r; cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    map<int,int> mp;
    set<pair<int,int>> st;
    int ans=0;
    for(int i=0 ; i<n ; i++){
        if(mp.find(a[i]) != mp.end()) st.erase({mp[a[i]],a[i]}); 
        mp[a[i]]=i;
        st.insert(make_pair(i,a[i]));
        if(st.size() < k) continue;
        if(st.size() > k+1) st.erase(st.begin());
        int lo,hi;
        if(st.size() == k){
            lo=i-st.begin()->first+1;
            hi=i+1;
        }else{
            lo=i-next(st.begin())->first+1;
            hi=i-st.begin()->first;
        }
        lo=max(lo,l); hi=min(hi,r);
        if(lo<=hi) ans+=hi-lo+1;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}