#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string s; cin >> s;
    int n=1000*(s[0]-'0')+100*(s[1]-'0')+10*(s[2]-'0')+(s[3]-'0');
    int tmp=sqrt(n);
    if(tmp*tmp == n){
        cout<<0<<" "<<tmp<<endl;
    }else{
        cout<<-1<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

