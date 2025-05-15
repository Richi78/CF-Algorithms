#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector< pair<int,int> > a(n);
    
    for(int i=0 ; i<n ; i++) {
        int x; cin >> x;
        a[i]={x,i+1};
    }
    sort(all(a), [](auto x, auto y){return x.F > y.F;});

    int cnt=0;
    int x=0;
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        a[i].F = a[i].F * x + 1;
        int val=a[i].F , idx=a[i].S;
        cnt+=val; x++; 
        ans.push_back(idx);
    }
    cout<<cnt<<endl;
    for(auto z : ans){
        cout<<z<<" ";
    }
    cout<<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

