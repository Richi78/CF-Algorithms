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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a(2,0);
    for(int i=0 ; i<n ; i++){
        if(s[i]=='1')a[1]++;
        else a[0]++;
    }

    while(k){
        // debug1(k)
        if(a[0]<2 && a[1]<2) break;
        int i = a[1]>a[0] ? 1 : 0;
        a[i]-=2; k--;
        // debug2(a[0],a[1])
    }
    // int tmp=abs(a[0]-a[1]);
    if(k==0 && a[0] == a[1])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

