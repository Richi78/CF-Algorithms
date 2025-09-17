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

auto cmp = [](const string &a, const string &b){
    if(a.size() == b.size()) return a<b;
    return a.size()<b.size();
};
set<string,decltype(cmp)> st(cmp);
int k;

void f(int idx, string &s, string cur){
    // if(st.size() > k) return;
    if(idx == -1){
        st.insert(cur);
        // mp[cur.size()]++;
        return;
    }

    // take
    f(idx-1, s, cur+s[idx]);
    // no take
    f(idx-1, s, cur);
}

void solve(){
    int n; cin >> n >> k;
    string s; cin >> s;

    f(n-1, s, "");
    if(st.size() < k){
        cout<<"-1\n"; return;
    }

    int sz=n;
    int cost=0;
    int ans=0;
    for (auto it = st.rbegin(); it != st.rend() && k; ++it) {
        const string &cur = *it;

        if ((int)cur.size() < sz) {
            sz = cur.size();
            cost++;
        }
        ans += cost;
        k--;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}