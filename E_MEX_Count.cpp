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

// const int N=2e5+100;
// int freq[N]={};

void solve(){
    int n; cin >> n;
    vector<int> freq(n+5);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        freq[x]++;
    }
    int mex=0;
    while(freq[mex] != 0) mex++;
    vector<int> ans(n+5);
    for(int i=0 ; i<=mex ; i++){
        int l=freq[i];
        int r=n-i;
        ans[l]++;
        ans[r+1]--;
    }
    for(int i=1 ; i<ans.size() ; i++){
        ans[i]+=ans[i-1];
    }
    for(int i=0 ; i<=n ; i++){
        cout<< ans[i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}