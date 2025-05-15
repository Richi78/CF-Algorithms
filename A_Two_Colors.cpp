#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m;cin>>n>>m;
    vi a(m);
    forn(i,m)cin>>a[i];
    sort(all(a));
    int total = 0;
    for (int k = 1; k < n; k++) {
        int x = k;
        int y = n - k;

        int cnt_x = m - (lower_bound(a.begin(), a.end(), x) - a.begin());

        int cnt_y = m - (lower_bound(a.begin(), a.end(), y) - a.begin());

        // int both = m - (lower_bound(a.begin(), a.end(), max(x, y)) - a.begin());
        // total += (1LL * cnt_x * cnt_y - both);
        total += (1LL * cnt_x * cnt_y - min(cnt_x,cnt_y));
        // cout<<"cnt_x: "<<cnt_x<<" cnt_y: "<<cnt_y<<" total: "<<total<<endl;
    }

    cout << total << '\n';
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}