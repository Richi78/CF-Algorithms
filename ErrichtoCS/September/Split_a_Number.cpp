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

string sum(string &a, string &b){
    if(b.size()>a.size()) swap(a,b);
    reverse(all(a)); reverse(all(b));

    string ans;
    bool carry=false;
    for(int i=0 ; i<(int)a.size() ; i++){
        int tmp=(a[i]-'0') + (i<(int)b.size()?(b[i]-'0'):0);
        if(carry) tmp++ , carry=false;
        if(tmp > 9) carry=true;
        ans.push_back((tmp%10)+'0');
    }
    if(carry) ans.push_back('1');
    reverse(all(ans));
    return ans;
}

string mn(string &a, string &b){
    if(a.size()<b.size()) return a;
    if(b.size()<a.size()) return b;
    return (a<b)?a:b;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    int mid=n/2;
    while(s[mid] == '0') mid++;
    string s1=s.substr(0,mid);
    string s2=s.substr(mid);
    ans=sum(s1,s2);
    if(n&1){
        string tmp=s.substr(0,mid+1);
        string tmp2=s.substr(mid+1);
        string x=sum(tmp,tmp2);
        ans=mn(ans,x);
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