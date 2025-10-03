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

const int MOD=1e4+7;

string get(string &a){
    string ans="";
    if(a.size()&1){
        return string( (a.size()-1)/2 , '9');
    }
    bool f=true;
    for(int i=0 ; i<a.size() ; i+=2){
        if( f ){
            if(a[i] > a[i+1]){
                ans.push_back(a[i]-1);
                f=false;
            }else{
                if(a[i] != a[i+1]) f=false;
                ans.push_back(a[i]);
            }
        }else{
            ans.push_back('9');
        }
    }
    return ans;
}

bool isTwin(string &s){
    for(int i=0 ; i<s.size() ; i+=2){
        if(s[i]!=s[i+1]) return false;
    }
    return true;
}

int f(int idx, bool tight, string &a, vector<vector<int>> &dp){
    if(idx == a.size()) return 1;
    if(dp[idx][tight] != -1) return dp[idx][tight];
    int ans=0;
    int limit=tight?(a[idx]-'0'):9;
    for(int i=0 ; i<=limit ; i++){
        bool newTight = tight && (i==limit);
        ans=(ans+f(idx+1, newTight , a, dp))%MOD;
    }
    return dp[idx][tight]=ans;
}

void solve(){
    string A,B; cin >> A >> B;
    string a=get(A) , b=get(B);
    int cnt_a=0 , cnt_b=0;
    vector<vector<int>> dp_a(a.size(), vector<int>(2,-1));
    for(int i=0 ; i<=9 ; i++){
        bool t=(a[0]-'0')==i;
        cnt_a=(cnt_a+f(1 , t , a , dp_a))%MOD;
        if(t)break;
    }
    vector<vector<int>> dp_b(b.size(), vector<int>(2,-1));
    for(int i=0 ; i<=9 ; i++){
        bool t=(b[0]-'0')==i;
        cnt_b=(cnt_b+f(1 , t , b , dp_b))%MOD;
        if(t)break;
    }
    int ans=cnt_b-cnt_a+MOD;
    if(isTwin(A))ans++;
    cout<< ans%MOD <<"\n";

    // a="1000";
    // a=get(a);
    // debug1(a)
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}