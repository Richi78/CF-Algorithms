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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(2);
    for(int i=0 ; i<n ; i++) a[s[i]-'0']++;

    if(a[0] == n){
        cout<<"NO"<<endl;
        return;
    }
    bool turn=1;
    int tmp=n;
    for(int i=0 ; i<n-1 ; i++){
        if(a[0]<=0 || a[1]<=0) break;
        if(turn) a[0]--;
        else a[1]--;
        turn=!turn;
    }
    if(a[0]==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}