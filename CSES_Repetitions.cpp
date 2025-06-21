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
    int ans=-1 , cnt=1;;
    for(int i=1 ; i<s.size() ; i++){
        if(s[i-1] == s[i]) cnt++;
        else {
            ans=max(ans,cnt);
            cnt=1; 
        } 
    }
    ans=max(ans,cnt);
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}