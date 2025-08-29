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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int left=n/2;
    int right=n/2+1;
    while(left>0 && s[left] == '0') left--;
    while(right<n && s[right] == '0') right++;
    
    vector<string> x;
    for(int rep=0 ; rep<2 ; rep++){
        string a=s.substr(0,left);
        string b=s.substr(left);
        string tmp=sum(a,b);
        x.push_back(tmp);
        left=right;
    }
    sort(all(x), [&](auto a, auto b){
        if(a.size() != b.size()) return a.size()<b.size();
        return a<b;
    });
    cout<< x[0] <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}