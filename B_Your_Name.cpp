#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define all(v) v.begin(),v.end()

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    vector<int> a(26) , b(26);
    for(int i=0 ; i<n ; i++){
        a[s1[i]-'a']++;
        b[s2[i]-'a']++;
    }
    // vdebug(a)
    // vdebug(b)
    for(int i=0 ; i<26 ; i++){
        if(a[i]!=b[i]){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n"; 
}
signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
    // solve();
}
