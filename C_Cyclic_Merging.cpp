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
    int n; cin >> n;
    vector<int> a(n);
    multiset<pair<int,int>> st;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        st.insert({a[i],i});
    }
    vector<int> prev(n);
    vector<int> next(n);
    for(int i=0 ; i<n ; i++){
        prev[i]=(i-1+n)%n;
        next[i]=(i+1)%n;
    }

    int ans=0;
    while(n>1){
        auto it=st.begin();
        int idx=it->second;

        int L=prev[idx];
        int R=next[idx];
        int best=(a[L]<a[R]?L:R);

        ans+=max(a[idx],a[best]);
        st.erase({a[best],best});
        
        st.erase({a[idx],idx});
        a[idx]=max(a[idx],a[best]);
        st.insert({a[idx],idx});

        if(best == L){
            prev[idx]=prev[best];
            next[prev[best]]=idx;
        }else{
            next[idx]=next[best];
            prev[next[best]]=idx;
        }
        n--;
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