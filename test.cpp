#include <bits/stdc++.h>
using namespace std;

#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 10007;

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

bool isTwin(const string &s){
    if(s.size() % 2 == 1) return false;
    for(int i=0 ; i<s.size() ; i+=2){
        if(s[i]!=s[i+1]) return false;
    }
    return true;
}

int countt(const string &a){
    int n = (int)a.size();
    vector<int> pow10(n+1);
    pow10[0]=1;
    for(int i=1;i<=n;i++) pow10[i] = (pow10[i-1]*10) % MOD;

    int cnt = 0;
    for(int i=0;i<n;i++){
        int d = a[i]-'0';
        cnt = (cnt + (d * 1LL * pow10[n-1-i]) % MOD) % MOD;
    }
    cnt = (cnt + 1) % MOD; 
    return cnt;
}

void solve(){
    string A,B; cin >> A >> B;
    string a = get(A);
    string b = get(B);

    int cnt_a = countt(a);
    int cnt_b = countt(b);

    // debug2(cnt_a,cnt_b) 

    int ans = (cnt_b - cnt_a + MOD) % MOD;
    if(isTwin(A)) ans = (ans + 1) % MOD;
    cout << ans << "\n";
}

signed main(){
    FIO;
    solve();
}
