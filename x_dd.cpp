#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int cantStres(int x, int y, vector<int> &a, vector<int> &b){
    int m=a[y] - a[x-1];
    int v=b[y] - b[x-1];
    return m * v;
}

void solve(){
    int n,c; cin >> n >> c;
    vector<int> people(n + 1); // 1-based
    for (int i = 1; i <= n; ++i) {
        cin >> people[i];
    }

    vector<int> prefix_m(n + 1, 0); 
    vector<int> prefix_v(n + 1, 0); 

    for (int i = 1; i <= n; ++i) {
        prefix_m[i] = prefix_m[i - 1] + (people[i] == 1 ? 1 : 0);
        prefix_v[i] = prefix_v[i - 1] + (people[i] == 0 ? 1 : 0);
    }


    vector<vector<int>> dp(n + 1, vector<int>(c + 1, INT_MAX));
    dp[0][0] = 0; // base: 0 personas en 0 cuartos

    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= min(c, i); ++k) {
            for (int j = k - 1; j < i; ++j) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + cantStres(j + 1, i,prefix_m,prefix_v));
            }
        }
    }
    for(auto x : dp){
        vdebug(x)
    }
    cout<<endl;
    cout << dp[n][c] << endl;
}

signed main(){
    FIO;
    solve();
}














