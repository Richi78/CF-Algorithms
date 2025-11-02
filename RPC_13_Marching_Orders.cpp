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

const int N=1e7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> target(n);
    for(int i = 0; i < n; i++) target[i] = s[i] - 'A';

    for(int m=0 ; m<N ; m++) {
        vector<int> list(n);
        for(int i=0 ; i<n ; i++) list[i]=i;
        bool ok = true;

        for(int i=0 ; i<n ; i++) {
            int pos = m % list.size();
            if(list[pos] != target[i]) {
                ok = false;
                break;
            }
            list.erase(list.begin() + pos);
        }

        if(ok) {
            cout << "YES\n" << m << "\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}