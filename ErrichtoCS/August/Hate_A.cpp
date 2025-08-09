#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string s; cin >> s;
    int n=s.size();
    int cnt_a=count(all(s),'a');
    if((n+cnt_a)&1){
        cout<<":(\n"; return;
    }

    int len=(n+cnt_a)/2;
    int i=0 , j=len;
    while(i<len && j<n){
        if(s[i]=='a'){
            i++;
            continue;
        }
        if(s[i] != s[j]){
            cout<< ":(\n"; return;
        }
        i++; j++;
    }
    cout<< s.substr(0,len) <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}