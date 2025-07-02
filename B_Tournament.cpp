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
    int n,j,k; cin >> n >> j >> k;
    vector<int> a;
    int x;
    for(int i=0 ; i<n ; i++){
        int tmp; cin >> tmp;
        if(i==j-1) x=tmp;
        else a.push_back(tmp);
    }

    if(a.size()==1){
        if(k==2)cout<<"YES\n";
        else{
            if(x>=a[0])cout<<"YES\n";
            else cout<<"NO\n";
        }
        return;
    }

    sort(all(a));
    int cnt=n-1;
    for(int i=0 ; i+1<n-1 && cnt>k; i++){
        cnt--;
    }

    // debug1(cnt)
    if(cnt != 1 && cnt <= k){
        cout<<"YES\n";
    }else{
        if(x>=a[n-2])cout<<"YES\n";
        else cout<<"NO\n";
    }
    // vdebug(a)
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}