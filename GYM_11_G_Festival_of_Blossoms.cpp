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

const int MOD=1e9+7;

vector<int> create_lps(string &needle){
    int n=(int)needle.size();
    vector<int> lps(n);

    int prevlps=0 , i=1;
    while(i<n){
        if(needle[i] == needle[prevlps]){
            lps[i]=prevlps+1;
            prevlps++; i++;
        }else if(prevlps == 0){
            lps[i]=0; i++;
        }else{
            prevlps=lps[prevlps-1];
        }
    }
    return lps;
}

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> lps=create_lps(s);
    int total=binexp(k,n);
    int m=s.size();
    
    // KMP transition table 
    vector<vector<int>> nxt(m + 1, vector<int>(k, 0));
    for (int st = 0; st < m; st++) {
        for (int c = 0; c < k; c++) {
            char ch = 'a' + c;
            int j = st;
            while (j > 0 && s[j] != ch) j = lps[j - 1];
            if (s[j] == ch) j++;
            nxt[st][c] = j;
        }
    }

    vector<int> dp(m, 0), newdp(m, 0);
    dp[0] = 1;

    for (int pos = 0; pos < n; pos++) {
        fill(all(newdp), 0);
        for (int st = 0; st < m; st++) {
            for (int c = 0; c < k; c++) {
                int ns = nxt[st][c];
                if (ns == m) continue; // contains S
                newdp[ns] = (newdp[ns] + dp[st]) % MOD;
            }
        }
        dp.swap(newdp);
    }

    int total_without = 0;
    for (int st = 0; st < m; st++) 
        total_without = (total_without + dp[st]) % MOD;
    int ans = (total - total_without + MOD) % MOD;
    cout << ans << "\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}