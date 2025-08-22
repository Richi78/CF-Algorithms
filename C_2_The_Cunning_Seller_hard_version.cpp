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

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

string toBase3(int n) {
    if (n == 0) return "0";
    string res;
    while(n) {
        res.push_back('0' + (n % 3));
        n /= 3;
    }
    reverse(all(res));
    return res;
}

int f(int n){
    int ans=binexp(3,n+1)+n*binexp(3,n-1);
    return ans;
}

void solve(){
    int n,k; cin >> n >> k;
    string s=toBase3(n);
    int sz=s.size()-1;
    int ans=0;
    int rest=0;
    int n_rest=0;
    for(int i=0 ; i<s.size() ; i++){
        rest+=c-'0';
        n_rest+=(s[i]-'0')*binexp(3,sz-i);
    }
    debug1(s)
    debug1(rest)
    for(int i=0 ; i<s.size() ; i++){
        if(k>=rest){
            int tmp=binexp(3,sz-i);
            ans+=(s[i]-'0')*3*tmp;
            rest-=(s[i]-'0');
            k-=(s[i]-'0');
            // break;
            continue;
        }
        if(s[i] == '0') continue;
        else{
            int one_deal=binexp(3,sz-i);
            
            if(k <= rest){
                cout<<"-1\n"; return;
            }
            if(i == s.size()-1){
                ans+=(s[i]-'0')*3;
                k-=(s[i]-'0');

            }else{
                if( (s[i]-'0') <= k ){
                    int tmp=(s[i]-'0')*f(sz-i);
                    ans+=tmp;
                    k-=(s[i]-'0');
                    rest-=(s[i]-'0');
                }
            }
        }
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