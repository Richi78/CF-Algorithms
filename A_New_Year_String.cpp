#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int a=0 , b=0;
    int i=0;
    while(i<n){
        if(i+3<n && s[i]=='2' && s[i+1]=='0' && s[i+2]=='2' && s[i+3]=='5'){
            a++;
        }
        if(i+3<n && s[i]=='2' && s[i+1]=='0' && s[i+2]=='2' && s[i+3]=='6'){
            b++;
        }
        i++;
    }
    if(b>0 || a==0) cout<<"0\n";
    else if(a>0) cout<<"1\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}