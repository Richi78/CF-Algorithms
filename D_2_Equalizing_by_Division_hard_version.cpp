#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int N=2e5+11;
vector<int> cnt[N];
void solve(){
    int n,k; cin >> n >> k; // n -> 2e5
    // vector< vector<int> > cnt(200 * 1000 + 7);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        int cur=0;
        while(x){
            cnt[x].push_back(cur);
            cur++; x>>=1;
        }
    }
    int ans=1e9;
    for(int i=0 ; i<2e5 ; i++){
        if(cnt[i].size() >= k){
            sort(all(cnt[i]));
            ans=min(ans , accumulate(cnt[i].begin(),cnt[i].begin()+k, 0LL));
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FIO;
    solve();
}